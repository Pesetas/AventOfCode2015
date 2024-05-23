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
    int x = MATRIX_SIZE/2;
    int y = MATRIX_SIZE/2;
    int a = MATRIX_SIZE/2;
    int b = MATRIX_SIZE/2;
    int turn = 1;
    int houses = 1;

    while (*str != '\0')
    {
        if (turn % 2 == 0)
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
        }
        else
        {
            if (*str == '<')
                a--;
            else if (*str == '>')
                a++;
            else if (*str == '^')
                b--;
            else if (*str == 'v')
                b++;
            check_house(m, a, b, &houses);
        }
        turn++;
        str++;
    }
    return (houses);
}

int main(void)
{
    int    **matrix;
    FILE    *file;
    char    buffer[MAX_LINE_LENGTH];
    
    file = fopen("./day3/3_b.txt", "r");
    if (file == NULL)
    {
        printf("Error opening text file");
        exit(1);
    }
    if (!fgets(buffer, MAX_LINE_LENGTH, file))
        return (1);
    fclose(file);
    matrix = create_matrix(MATRIX_SIZE);
    printf("houses = %d\n", calculate_houses(matrix, buffer));
    free_matrix(matrix, MATRIX_SIZE);
    return (0);
}