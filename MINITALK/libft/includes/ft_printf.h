/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:00:24 by tsemenov          #+#    #+#             */
/*   Updated: 2025/06/23 12:00:27 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
// # include "libft.h"

# define NULL_PTR "(nil)"

char	*ft_itoa_mod(int n);
int		ft_print_unsigned(unsigned int c);
int		ft_printf(const char *format, ...);
int		ft_printchar(int c);
int		ft_printhex(unsigned long num, const char c);
int		ft_printnum(int c);
int		ft_printptr(void *ptr);
int		ft_printpercent(void);
int		ft_printstr(char *s);
int		ft_print_unsigned(unsigned int c);
void	ft_to_hex(unsigned long num, char *s, int *i);
void	ft_to_bighex(unsigned long num, char *s, int *i);
char	*ft_utoa(unsigned int n);

#endif
