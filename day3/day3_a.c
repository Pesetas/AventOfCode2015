#include "../inc/advent.h"

static void check_house(int **m, int x, int y, int *houses)
{
    if(m[x][y] == 0)
    {
        m[x][y] = 1;
        (*houses)++;
    }
}

static int  calculate_houses(int **m, char *str)
{
    int x = 500;
    int y = 500;
    int houses = 1;

    while (*str != '\0')
    {
        if (*str == '<')
            x--;
        else if (*str == '>')
            x++;

        else if (*str == '^')
            y--;
        else if (*str == 'v')
            y++;
        check_house(m, x, y, &houses);
        str++;
    }
    return (houses);
}

int main(int argc, char **argv)
{
    int    **matrix;
    FILE    *file;
    char    buffer[MAX_LINE_LENGTH];

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
    if (!fgets(buffer, MAX_LINE_LENGTH, file))
        return (1);
    fclose(file);
    matrix = create_matrix(MATRIX_SIZE);
    matrix[MATRIX_SIZE/2][MATRIX_SIZE/2] = 1;
    printf("houses = %d\n", calculate_houses(matrix, buffer));
    free_matrix(matrix, MATRIX_SIZE);
    return (0);
}