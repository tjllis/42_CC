/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:42:46 by tsemenov          #+#    #+#             */
/*   Updated: 2024/11/14 12:42:47 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*stemp;
	size_t	i;
	char	*dtemp;

	dtemp = (char *)dest;
	stemp = (char *)src;
	if (!dest && !src)
		return (NULL);
	if (n == 0)
		return (dest);
	if (dtemp < stemp)
		ft_memcpy(dtemp, stemp, n);
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			dtemp[i] = stemp[i];
		}
	}
	return (dest);
}
