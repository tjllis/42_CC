#include "libft.h"

int	ft_atoi_safe(char *str, int *result)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	num = num * sign;
	if (num < INT_MIN || num > INT_MAX)
		return (ATOI_FAIL);
	*result = (int)num;
	return (ATOI_SUCCESS);
}