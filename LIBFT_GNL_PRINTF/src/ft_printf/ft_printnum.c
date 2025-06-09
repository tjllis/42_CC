/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:22:01 by tsemenov          #+#    #+#             */
/*   Updated: 2024/12/17 14:47:37 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnum(int c)
{
	char	*s;
	int		i;

	i = 0;
	s = ft_itoa_mod(c);
	if (!s)
	{
		ft_printstr("(null)");
		return (6);
	}
	i = ft_printstr(s);
	free(s);
	return (i);
}
