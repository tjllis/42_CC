/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:54:40 by tsemenov          #+#    #+#             */
/*   Updated: 2024/12/10 13:10:33 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int c)
{
	char	*s;
	int		i;

	i = 0;
	s = ft_utoa(c);
	if (!s)
	{
		ft_printstr("(null)");
		return (6);
	}
	i = ft_printstr(s);
	free(s);
	return (i);
}
