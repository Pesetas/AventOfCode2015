#include "../inc/advent.h"
#include <openssl/evp.h>


static int looking_for_Xzeros(char *str)
{
	int num_zeros;

	num_zeros = 0;
	while(*str != '\0')
	{
		if(*str != '0')
			return (0);
		num_zeros++;
		if (num_zeros == 5)	// Modify this to change number of zeros
		{
			return (1);
		}
		str++;
	}
	return (0);
}

static void	adding_digits(char *str)
{
	char		*str_num;
	static int	num = 0;

	str_num = ft_itoa(num);
	strncat(str, str_num, strlen(str_num) + 1);
	free(str_num);
	str_num = NULL;
	num++;
}

int main(int argc, char **argv)	{
	char	*text = malloc(sizeof(char) * 64);
	char	md5_result[EVP_MAX_MD_SIZE * 2 + 1];  // Máximo tamaño del digest + null terminator
	char	*cpy = malloc(sizeof(char) * 64);

	if (!argv[1])
	{
		fprintf(stderr, "You must input a text string as an argument.");
		return (1);
	}
	(void) argc;
	ft_strlcpy(text, argv[1], 64);
	calculate_md5(text, md5_result);
	while (looking_for_Xzeros(md5_result) != 1)
	{
		ft_strlcpy(cpy, text, strlen(text) + 1);
		adding_digits(cpy);
		calculate_md5(cpy, md5_result);
	}
	fprintf(stderr, "MD5 hash de '%s' es: %s\n", cpy, md5_result);
	free(text);
	free(cpy);
	return 0;
}
 
