#include "../inc/advent.h"

int	matrix_size = 1000; 

typedef struct s_coordinate
{
	int	x;
	int	y;
}	t_coordinate;

typedef struct s_datos
{
	t_coordinate	start;
	t_coordinate	end;
}	t_data;

void	extract_data(char *str, t_data *data)
{
	while (isdigit(*str) == 0)
		str++;
	data->start.x = atoi(str);
	while (*str != ',')
		str++;
	str++;
	data->start.y = atoi(str);
	while (isdigit(*str) != 0)
		str++;
	while (isdigit(*str) == 0)
		str++;
	data->end.x = atoi(str);
	while (*str != ',')
		str++;
	str++;
	data->end.y = atoi(str);
}

static void	toggle(int **matrix, t_data *data)
{
	if (data->start.x < 0 || data->end.x >= matrix_size || data->start.y < 0 || data->end.y >= matrix_size)
	{
		fprintf(stderr, "Error: Indices fuera de los límites de la matriz.\n");
		return;
	}

	for(int x = data->start.x; x <= data->end.x; x++)
	{
		for(int y = data->start.y; y <= data->end.y; y++)
		{
			if (matrix[x][y] == 0)
				matrix[x][y] = 1;
			else if (matrix[x][y] == 1)
				matrix[x][y] = 0;
			else
			{
				fprintf(stderr, "Error: Valor inesperado en matrix[%d][%d] = %d\n", x, y, matrix[x][y]);
				return;
			}
		}
	}
}

static void	turn_on(int **matrix, t_data *data)
{
	for(int x = data->start.x; x <= data->end.x; x++)
		for(int y = data->start.y; y <= data->end.y; y++)
			matrix[x][y] = 1;
}

static void	turn_off(int **matrix, t_data *data)
{
	for(int x = data->start.x; x <= data->end.x; x++)
		for(int y = data->start.y; y <= data->end.y; y++)
			matrix[x][y] = 0;
}

static int	count_lights(int **matrix)
{
	int	lights;

	lights = 0;
	for(int x = 0; x < matrix_size; x++)
		for(int y = 0; y < matrix_size; y++)
			if (matrix[x][y] == 1)
				lights++;
	return (lights);
}

static int	day6(char *str, int **matrix)
{
	t_data	data;
	int		lights;

	extract_data(str, &data);	
	if (str[1] == 'o')
	{
		toggle(matrix, &data);
	}
	if (str[6] == 'f')  
	{
		turn_off(matrix, &data);
	}
	if (str[6] == 'n')
	{
		turn_on(matrix, &data);
	}
	lights = count_lights(matrix);
	
	return (lights);
}

int main(int argc, char **argv)
{
	FILE	*file;
	char	buffer[MAX_LINE_LENGTH];
	int		**matrix;
	int		lights;

	(void)argc;
	if (!argv[1])
	{
		fprintf(stderr, "You must input a file as an argument.");
		return (1);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error opening text file");
		exit(1);
	}
	matrix = create_matrix(matrix_size);
	while (fgets(buffer, MAX_LINE_LENGTH, file) != 0)
		lights = day6(buffer, matrix);
	printf("Total lights on = %d", lights);
	fclose(file);
	free_matrix(matrix, matrix_size);
	return (0);
}