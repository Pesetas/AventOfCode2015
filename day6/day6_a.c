#include "../inc/advent.h"

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
	
}

static void	day6(char *str, char **matrix)
{
	t_data	data;

	extract_data(str, &data);
	/*
	if (str[1] == 'o')
	{
		toggle();
	}
	if (str[6] == 'f')
	{
		turn_off("off ");
	}
	if (str[6] == 'n')
	{
		turn_on
	}
		printf("on ");
		*/
}
/*
Hacer las tres una función?
static void	toggle(char **matrix, t_datos datos)
static void	turn_on(char **matrix, t_datos datos)
static void	turn_off(char **matrix, t_datos datos)
*/
int main(int argc, char **argv)
{
	FILE	*file;
	char	buffer[MAX_LINE_LENGTH];
	char	**matrix;

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
	matrix = create_matrix(1000);
	while (fgets(buffer, MAX_LINE_LENGTH, file) != 0)
		day6(buffer, matrix);
	fclose(file);
	free_matrix(matrix, 1000);
	return (0);
}