/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:19:59 by tsemenov          #+#    #+#             */
/*   Updated: 2025/06/23 12:20:00 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_point(t_point *point)
{
	point->z = 0;
	point->color = PINK;
	point->has_color = 0;
}

int	parse_point_simple(char *str, t_point *point)
{
	point->z = ft_atoi(str);
	point->has_color = 0;
	return (CHECK_OK);
}

int	parse_point_color(char *str, t_point *point)
{
	char	**info;
	char	*start_color;

	info = ft_split(str, ',');
	if (info == NULL || info[0] == NULL || !is_valid_int(info[0]) || \
		ft_atoi_safe(info[0], &point->z) != ATOI_SUCCESS)
	{
		if (info)
			free_matrix(info);
		return (CHECK_ERROR);
	}
	if (info[1] != NULL)
	{
		start_color = info[1];
		if (start_color[0] == '0' && \
			(start_color[1] == 'x' || start_color[1] == 'X'))
			start_color += 2;
		if (is_valid_color(start_color))
		{
			point->color = ft_atoi_base(start_color, 16);
			point->has_color = 1;
		}
	}
	free_matrix(info);
	return (CHECK_OK);
}

int	parse_point(char *str, t_point *point)
{
	if (str == NULL || point == NULL)
		return (CHECK_ERROR);
	init_point(point);
	if (ft_strchr(str, ',') != NULL)
		return (parse_point_color(str, point));
	else
		return (parse_point_simple(str, point));
}
