int day1_a(char *str)
{
    int     sum; 
    
    sum = 0;
    while (*str != '\0')
    {
        if (*str == '(')
            sum++;
        else
            sum--;
        str++;
    }
    return (sum);
}