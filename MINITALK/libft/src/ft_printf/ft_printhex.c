/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:46:10 by tsemenov          #+#    #+#             */
/*   Updated: 2024/12/17 14:46:12 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned long num, const char c)
{
	int		count;
	int		i;
	char	*s;

	count = 0;
	i = 0;
	s = malloc(20);
	if (s == NULL)
		return (0);
	if (c == 'x')
		ft_to_hex(num, s, &i);
	else if (c == 'X')
		ft_to_bighex(num, s, &i);
	s[i] = '\0';
	count = ft_printstr(s);
	free(s);
	return (count);
}
