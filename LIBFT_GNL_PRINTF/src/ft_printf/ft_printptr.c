/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:49:13 by tsemenov          #+#    #+#             */
/*   Updated: 2024/12/17 14:49:14 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptr(void *ptr)
{
	char	*buf;
	int		i;
	int		count;

	if (ptr == NULL)
	{
		ft_printstr(NULL_PTR);
		return (5);
	}
	i = 0;
	count = 0;
	buf = malloc(20);
	if (buf == NULL)
		return (-1);
	buf[i++] = '0';
	buf[i++] = 'x';
	ft_to_hex((unsigned long)ptr, buf, &i);
	buf[i] = '\0';
	count = ft_printstr(buf);
	free(buf);
	return (count);
}
