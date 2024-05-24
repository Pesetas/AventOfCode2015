#include "../inc/advent.h"
#include <openssl/evp.h>


static int looking_for_5zeros(char *str)
{
	int num_zeros;

	num_zeros = 0;
	while(*str != '\0')
	{
		if(*str != '0')
			return (0);
		num_zeros++;
		if (num_zeros == 5)
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

int main()	{
	char	*text = malloc(sizeof(char) * 64);
	char	md5_result[EVP_MAX_MD_SIZE * 2 + 1];  // Máximo tamaño del digest + null terminator
	char	*cpy = malloc(sizeof(char) * 64);

	ft_strlcpy(text, "bgvyzdsv", 64);
	calculate_md5(text, md5_result);
	while (looking_for_5zeros(md5_result) != 1)
	{
		ft_strlcpy(cpy, text, strlen(text) + 1);
		adding_digits(cpy);
		calculate_md5(cpy, md5_result);
	}
	fprintf(stderr, "MD5 hash de '%s' es: %s\n", cpy, md5_result);
	return 0;
}
 