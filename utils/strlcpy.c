#include "../inc/advent.h"

/*
The strcpy() function copies the string pointed to by src, including the 
terminating null byte ('\0'), to the buffer pointed to by dest.  The strings 
may not overlap, and the destination string dest must be large enough 
to receive the copy.
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (strlen(src));
	while (i < (dstsize - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (strlen(src));
}
