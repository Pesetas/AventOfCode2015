int day1_b(char *str)
{
    int sum;
    int pos;
    
    sum = 0;
    pos = 0;
    while (str[pos] != '\0')
    {
        if (str[pos] == '(')
            sum++;
        else
            sum--;
        pos++;
        if (sum == -1)
            return (pos);
    }
    return (pos);
}