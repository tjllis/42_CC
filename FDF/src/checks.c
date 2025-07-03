/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:17:41 by tsemenov          #+#    #+#             */
/*   Updated: 2025/06/23 12:17:42 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_fdf(char *filename)
{
	int		len;
	char	*ext;

	if (filename == NULL)
		return (CHECK_ERROR);
	len = ft_strlen(filename);
	if (len < 4)
		return (CHECK_ERROR);
	ext = filename + (len - 4);
	if (ft_strncmp(ext, ".fdf", 4) == 0)
		return (CHECK_OK);
	return (CHECK_ERROR);
}

int	is_valid_int(char *str)
{
	int	i;

	if (str == NULL || *str == '\0')
		return (CHECK_ERROR);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (CHECK_ERROR);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (CHECK_ERROR);
		i++;
	}
	return (CHECK_OK);
}

int	is_valid_color(char *str)
{
	int	i;
	int	len;

	if (str == NULL || *str == '\0')
		return (CHECK_ERROR);
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		str += 2;
	len = ft_strlen(str);
	if (len == 0 || len > 6)
		return (CHECK_ERROR);
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) || (str[i] >= 'a' && str[i] <= 'f') || \
			(str[i] >= 'A' && str[i] <= 'F'))
			i++;
		else
			return (CHECK_ERROR);
	}
	return (CHECK_OK);
}
