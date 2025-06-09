/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:52:46 by tsemenov          #+#    #+#             */
/*   Updated: 2024/12/17 14:52:47 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_len(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static void	strfill(char *s, unsigned int nb, int i)
{
	if (nb == 0)
		return ;
	strfill(s, nb / 10, i - 1);
	s[i] = (nb % 10) + '0';
}

char	*ft_utoa(unsigned int n)
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
		strfill(str, n, len - 1);
	return (str);
}
