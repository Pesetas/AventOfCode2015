#include "../inc/advent.h"

static void get_dimensions_valours(char *str, int *x, int *y, int *z)
{
    *x = atoi(str);
    while(*str != 'x')
        str++;
    str++;
    *y = atoi(str);
    while(*str != 'x')
        str++;
    str++;
    *z = atoi(str);
}

static int  surface_area(int x, int y, int z)
{
    return (2*x*y + 2*x*z + 2*y*z);
}

static int  get_min(int x, int y, int z)
{
    if ((x*y <= x*z) && (x*y <= y*z))
        return (x*y);
    if ((y*z <= x*y) && (y*z <= x*z))
        return (y*z);
    return (x*z);
}

static int  calculating(char *str)
{
    int x, y, z;
    int area, min_area;

    get_dimensions_valours(str, &x, &y, &z);
    area = surface_area(x, y, z);
    min_area = get_min(x, y, z);

    return (area + min_area);
}

int day2_a()
{
    FILE    *file;
    char    buffer[MAX_LINE_LENGTH];
    int     sum;

    file = fopen("2_a.txt", "r");
    if (file == NULL)
    {
        printf("Error");
        exit(1);
    }
    while(fgets(buffer, MAX_LINE_LENGTH, file) != NULL)
    {
        sum += calculating(buffer);
    }
    fclose(file);
    return (sum);
}

int main(void)
{
    printf("%d", day2_a());
    return 0;
}