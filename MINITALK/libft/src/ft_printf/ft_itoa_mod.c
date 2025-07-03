/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:39:51 by tsemenov          #+#    #+#             */
/*   Updated: 2024/12/10 12:25:26 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_len(int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		if (num == INT_MIN)
			return (11);
		len = 1;
		num = -num;
	}
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static void	strfill(char *s, int nb, int i)
{
	if (nb == 0)
		return ;
	strfill(s, nb / 10, i - 1);
	s[i] = (nb % 10) + '0';
}

static int	handle_int_min(char *str, int n)
{
	if (n == INT_MIN)
	{
		str[1] = '2';
		n = 147483648;
	}
	return (n);
}

char	*ft_itoa_mod(int n)
{
	int		len;
	char	*str;

	len = get_len(n);
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	else
	{
		if (n < 0)
		{
			str[0] = '-';
			if (n == INT_MIN)
				n = handle_int_min(str, n);
			else
				n = -n;
		}
		strfill(str, n, len - 1);
	}
	return (str);
}
