/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:19:49 by tsemenov          #+#    #+#             */
/*   Updated: 2025/06/23 12:19:50 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	allocate_rows(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		map->points[i] = malloc(sizeof(t_point) * map->width);
		if (map->points[i] == NULL)
		{
			while (i > 0)
			{
				i--;
				free(map->points[i]);
			}
			free(map->points);
			return (CHECK_ERROR);
		}
		i++;
	}
	return (CHECK_OK);
}

int	allocate_map_data(t_map *map)
{
	if (map->width <= 0 || map->height <= 0)
	{
		ft_putstr_fd("Invalid map dimensions\n", 2);
		return (CHECK_ERROR);
	}
	map->points = malloc(sizeof(t_point *) * map->height);
	if (map->points == NULL)
	{
		ft_putstr_fd("Memory allocation failed for 2d map data\n", 2);
		return (CHECK_ERROR);
	}
	if (allocate_rows(map) != CHECK_OK)
	{
		free(map->points);
		ft_putstr_fd("Memory allocation failed for 2d map rows\n", 2);
		return (CHECK_ERROR);
	}
	return (CHECK_OK);
}
