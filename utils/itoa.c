#include "../inc/advent.h"

static int	ft_numchar(int n)
{
	int	result;

	result = 0;
	if (n == 0)
		return (result + 1);
	if (n < 0)
	{
		if (n == -2147483648)
			return (11);
		n = -n;
		result++;
	}
	while (n > 0)
	{
		n = n / 10;
		result++;
	}
	return (result);
}

static void	ft_negative_itoa(char *str, int *n, int *i)
{
	str[0] = '-';
	if (*n == -2147483648)
	{
		str[*i] = '8';
		*i = *i - 1;
		*n = -214748364;
	}
	*n = -*n;
}

/* 
Using malloc(3), generate a string that represent the integer value 
received as an argument. Negative numbers have to be managed.
*/
char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	str = malloc((sizeof(*str) * ft_numchar(n)) + 1);
	if (!str)
		return (NULL);
	i = ft_numchar(n);
	str[i--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		ft_negative_itoa(str, &n, &i);
	while (n > 0)
	{
		str[i--] = 48 + n % 10;
		n = n / 10;
	}
	return (&str[0]);
}