#ifndef ADVENT_H
# define ADVENT_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

# define MAX_LINE_LENGTH 16384

int day1_a(char *str);
int day1_b(char *str);
int day2_a();
int day2_b();

/* -- UTILS -- */

# define MATRIX_SIZE 10000

int     **create_matrix(size_t size);
void    free_matrix(int **m, size_t size);

char	*ft_itoa(int n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

void calculate_md5(const char *str, char *md5_result);

#endif