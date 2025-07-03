/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:14:59 by tsemenov          #+#    #+#             */
/*   Updated: 2024/11/15 17:15:07 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*p;
	size_t			arr_size;
	size_t			i;

	if (nmemb != 0 && ((nmemb * size) / nmemb != size))
		return (NULL);
	i = 0;
	arr_size = nmemb * size;
	p = malloc(arr_size);
	if (!p)
		return (NULL);
	while (i < arr_size)
	{
		p[i] = 0;
		i++;
	}
	return (p);
}
