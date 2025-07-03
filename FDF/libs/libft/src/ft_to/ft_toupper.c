/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:50:27 by tsemenov          #+#    #+#             */
/*   Updated: 2024/11/11 15:50:28 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c - 32);
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	int c = 'c';
	printf("Original: %d\n", toupper(c));
	printf("Original: %c\n", toupper(c));
	printf("Custom: %d\n", ft_toupper(c));
	printf("Custom: %c\n", ft_toupper(c));
	return (0);
}*/
