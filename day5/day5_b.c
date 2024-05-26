#include "../inc/advent.h"

static int	find_pair(char *str, char *pair, size_t pos)
{
	size_t	size;

	size = strlen(str);
	for (size_t i = 3; i < size; i++)
	{
		if (pair[1] == str[i] && pair[0] == str[i-1])
			if ((i != pos) && ((i-1) != pos))
			{
				fprintf(stderr, "%s: %s\n", str, pair);
				return(1);
			}
	}
	return (0);
}

static int	contains_pair(char *str)
{
	size_t	size;
	char	*pair;

	if (!(pair = malloc(sizeof(char) * 2 + 1)))
		return (-1);
	size = strlen(str);
	for (size_t i = 1; i < size; i++)
	{
		pair[0] = str[i-1];
		pair[1] = str[i];
		pair[2] = '\0';
		if (find_pair(str, pair, i-1))
			return (1);
	}
	return (0);
}

static int	between(char *str)
{
	size_t	size;

	size = strlen(str);
	for (size_t i = 2; i < size; i++)
	{
		if ((str[i] != str[i-1]) && (str[i] == str[i-2]))
			return (1);
	}
	return (0);
}

static int	day5(int x, int y) 
{
	if ((x + y) == 2)
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
		sum += day5(contains_pair(buffer), between(buffer));
	}
	fclose(file);
	printf("%d", sum);
	return (0);
}