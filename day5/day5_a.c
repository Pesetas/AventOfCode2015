#include "../inc/advent.h"

static int	contains_string(char *str)
{
	size_t	size;

	size = strlen(str);
	for (size_t i = 0; i < size - 1; i++)
	{
		switch (str[i])
		{
		case 'a':
			if (str[i + 1] == 'b')
				return (0);
			break;
		case 'c':
			if (str[i + 1] == 'd')
				return (0);
			break;
		case 'p':
			if (str[i + 1] == 'q')
				return (0);
			break;
		case 'x':
			if (str[i + 1] == 'y')
				return (0);
			break;
		default:
			break;
		}
	}
	return (1);
}

static int	twice(char *str)
{
	size_t	size;

	size = strlen(str);
	for (size_t i = 1; i < size; i++)
	{
		if (str[i] == str[i-1])
			return (1);
	}
	return (0);
}

static int	vocals(char *str)
{
	int	a = 0;
	int e = 0;
	int i = 0;
	int o = 0;
	int u = 0;
	int	num = 0;

	while(*str != '\0')
	{
		switch (*str)
		{
		case 'a':
			a += 1;
			break;
		case 'e':
			e += 1;
			break;
		case 'i':
			i += 1;
			break;
		case 'o':
			o += 1;
			break;
		case 'u':
			u += 1;
			break;
		default:
			break;
		}
		str++;
	}
	num = a + e + i + o + u;
	if (num > 2)
		return(1);
	else
		return (0);
}

static int	day5(int x, int y, int z)
{
	if ((x + y + z) == 3)
		return (1);
	return (0);
}

int main(int argc, char **argv)
{
	FILE    *file;
	char    buffer[MAX_LINE_LENGTH];
	int		sum;

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
	sum = 0;
	while(fgets(buffer, MAX_LINE_LENGTH, file) != NULL)
	{
		sum += day5(contains_string(buffer), twice(buffer), vocals(buffer));
	}
	fclose(file);
	printf("%d", sum);
	return (0);
}