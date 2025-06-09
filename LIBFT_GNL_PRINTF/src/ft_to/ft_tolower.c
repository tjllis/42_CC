/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:02:23 by tsemenov          #+#    #+#             */
/*   Updated: 2024/11/11 16:02:24 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c + 32);
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	int c = 'C';
	printf("Original: %d\n", tolower(c));
	printf("Original: %c\n", tolower(c));
	printf("Custom: %d\n", ft_tolower(c));
	printf("Custom: %c\n", ft_tolower(c));
	return (0);
}*/
