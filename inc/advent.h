#ifndef ADVENT_H
# define ADVENT_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <ctype.h>

# define MAX_LINE_LENGTH 2048
# define MATRIX_SIZE 10000

int     **create_matrix(size_t size);
void    free_matrix(int **m, size_t size);

char	*ft_itoa(int n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

void calculate_md5(const char *str, char *md5_result);

// Matrix struct used in exercise 6 //

typedef struct s_coordinate
{
	int	x;
	int	y;
}	t_coordinate;

typedef struct s_datos
{
	t_coordinate	start;
	t_coordinate	end;
}	t_data;

#endif