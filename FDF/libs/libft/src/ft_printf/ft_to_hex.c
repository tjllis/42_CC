/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:51:47 by tsemenov          #+#    #+#             */
/*   Updated: 2024/12/17 14:51:49 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_to_hex(unsigned long num, char *s, int *i)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (num >= 16)
		ft_to_hex(num / 16, s, i);
	s[(*i)++] = hex[num % 16];
}
