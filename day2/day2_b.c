#include "../inc/advent.h"

static void get_dimensions_valours(char *buffer, int *x, int *y, int *z)
{
    *x = atoi(buffer);
    while(*buffer != 'x')
        buffer++;
    buffer++;
    *y = atoi(buffer);
    while(*buffer != 'x')
        buffer++;
    buffer++;
    *z = atoi(buffer);
}

static void  get_min(int x, int y, int z, int *min1, int *min2)
{
    if ((x * y) <= (x * z) && (x * y) <= (y * z))
    {
        *min1 = x;
        *min2 = y;
    }  
    if ((x * z) <= (x * y) && (x * z) <= (y * z))
    {
        *min1 = x;
        *min2 = z;
    } 
    if ((y * z) <= (x * y) && (y * z) <= (x * z))
    {
        *min1 = y;
        *min2 = z;
    }  
}

static int  get_ribbon_dimension(int x, int y, int z)
{
    int dimension;
    int min1, min2;
    
    get_min(x, y, z, &min1, &min2);
    dimension = 2 * min1 + 2 * min2;
    dimension += x * y * z;
    return (dimension);
}

static int  calculating(char *buffer)
{
    int x, y, z;
    int ribbon;

    get_dimensions_valours(buffer, &x, &y, &z);
    ribbon = get_ribbon_dimension(x, y, z);
    return (ribbon);
}

int day2_b()
{
    FILE    *file;
    char    buffer[MAX_LINE_LENGTH];
    int     sum;

    file = fopen("2_b.txt", "r");
    if (file == NULL)
    {
        printf("Error");
        exit(1);
    }
    sum = 0;
    while(fgets(buffer, MAX_LINE_LENGTH, file) != NULL)
    {
        sum += calculating(buffer);
    }
    fclose(file);
    return (sum);
}

int main(void)
{
    printf("%d", day2_b());
    return 0;
}