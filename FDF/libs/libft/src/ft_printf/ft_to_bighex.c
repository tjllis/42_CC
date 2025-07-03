/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_bighex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:52:15 by tsemenov          #+#    #+#             */
/*   Updated: 2024/12/17 14:52:16 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_to_bighex(unsigned long num, char *s, int *i)
{
	char	*hex;

	hex = "0123456789ABCDEF";
	if (num >= 16)
		ft_to_bighex(num / 16, s, i);
	s[(*i)++] = hex[num % 16];
}
