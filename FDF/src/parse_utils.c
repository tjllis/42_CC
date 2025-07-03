/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:20:12 by tsemenov          #+#    #+#             */
/*   Updated: 2025/06/23 12:20:12 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_width(char *line, int *width)
{
	char	**split;

	*width = 0;
	split = ft_split(line, ' ');
	if (split == NULL)
		return (CHECK_ERROR);
	while (split[*width] != NULL)
		(*width)++;
	free_matrix(split);
	return (CHECK_OK);
}

int	is_valid_width(char **split, int width)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
		i++;
	if (i != width)
		return (CHECK_ERROR);
	return (CHECK_OK);
}

int	get_height(int fd, int *height)
{
	char	*line;

	*height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		(*height)++;
		free(line);
		line = get_next_line(fd);
	}
	return (CHECK_OK);
}

int	parse_line(t_map *map, char *line, int row)
{
	char	**split;
	int		result;

	split = ft_split(line, ' ');
	if (split == NULL || split[0] == NULL || ft_isspace(split[0][0]))
	{
		if (split)
			free_matrix(split);
		return (CHECK_ERROR);
	}
	if (is_valid_width(split, map->width) != CHECK_OK)
	{
		free_matrix(split);
		return (CHECK_ERROR);
	}
	result = fill_row(map, split, row);
	free_matrix(split);
	return (result);
}

int	fill_row(t_map *map, char **split, int row)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if ((parse_point(split[i], &map->points[row][i])) != CHECK_OK)
			return (CHECK_ERROR);
		i++;
	}
	return (CHECK_OK);
}
