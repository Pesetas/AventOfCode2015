#include "../inc/advent.h"

 int  **create_matrix(size_t size)
{
    int rows = size;
    int cols = size;
    int **m;    
    m = (int **)calloc(rows, sizeof(int *));
    if (m == NULL)
    {
        fprintf(stderr, "memory error");
        return (NULL);
    }
    for (int i = 0; i < rows; i++)
    {
        m[i] = (int *)calloc(cols, sizeof(int));
        if (m == NULL)
        {
            fprintf(stderr, "memory error");
            return (NULL);
        }
    }
    return (m);
}

void    free_matrix(int **m, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        free(m[i]);
        m[i] = NULL;
    }
    free(m);
    m = NULL;
}