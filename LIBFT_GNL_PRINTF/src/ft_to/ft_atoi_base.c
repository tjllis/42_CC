#include "libft.h"

static int	is_space(char c)
{
	return (c <= 32);
}

static int	char_to_dec(char c)
{
	if ('0' <= c && c <= '9')
		return (c - '0');
	else if ('a' <= c && c <= 'f')
		return (c - 'a' + 10);
	else if ('A' <= c && c <= 'F')
		return (c - 'A' + 10);
	else
		return (0);
}

static int	is_valid(char c)
{
	return (('0' <= c && c <= '9') || ('a' <= c && c <= 'f')
		|| ('A' <= c && c <= 'F'));
}

int	ft_atoi_base(const char *str, int str_base)
{
	int		i;
	int		sign;
	int		result;
	char	c;

	if (str_base < 2 || str_base > 16)
		return (0);
	i = 0;
	sign = 1;
	result = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && is_valid(str[i]))
	{
		c = char_to_dec(str[i]);
		result = result * str_base + c;
		i++;
	}
	return (result * sign);
}
// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d\n", ft_atoi_base(" 0123", 8));
// 	printf("%d\n", ft_atoi_base("0", 5));
// 	printf("%d\n", ft_atoi_base("+FF", 16));
// 	printf("%d\n", ft_atoi_base("1G", 16));
// 	printf("%d\n", ft_atoi_base("123", 5));
// }
