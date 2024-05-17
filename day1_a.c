#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    char    *cadena = "()((((";
    int     sum = 0;

    while (*cadena != '\0')
    {
        if (*cadena == '(')
            sum++;
        else
            sum--;
        cadena++;
    }

    printf("%d", sum);

    return 0;
}