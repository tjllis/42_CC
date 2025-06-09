/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:48:32 by tsemenov          #+#    #+#             */
/*   Updated: 2024/12/17 18:21:36 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(const char c, va_list args);

int	ft_printf(const char *format, ...)
{
	const char	*s;
	va_list		args;
	int			count;
	int			result;

	va_start(args, format);
	count = 0;
	s = format;
	if (s == NULL)
		return (-1);
	while (*s != '\0')
	{
		if (*s == '%')
		{
			result = check_format(*(++s), args);
			if (result < 0)
				return (-1);
			count += result;
		}
		else
			count += write(1, s, 1);
		++s;
	}
	va_end(args);
	return (count);
}

int	check_format(const char c, va_list args)
{
	int	count;
	int	result;

	count = 0;
	result = 0;
	if (c == 'c')
		result = ft_printchar(va_arg(args, int));
	else if (c == 's')
		result = ft_printstr(va_arg(args, char *));
	else if (c == 'i' || c == 'd')
		result += ft_printnum(va_arg(args, int));
	else if (c == 'u')
		result += ft_print_unsigned(va_arg(args, unsigned int));
	else if (c == 'p')
		result += ft_printptr(va_arg(args, unsigned int *));
	else if (c == 'x' || c == 'X')
		result += ft_printhex(va_arg(args, unsigned int), c);
	else
		result += ft_printpercent();
	if (result < 0)
		return (-1);
	count += result;
	return (count);
}
