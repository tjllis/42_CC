/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:19:41 by tsemenov          #+#    #+#             */
/*   Updated: 2025/06/23 12:19:42 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	parse_map(t_map *map, char *filename, char **error_msg)
{
	if (is_fdf(filename) != CHECK_OK)
	{
		*error_msg = "Invalid file format. Expected .fdf file\n";
		return (CHECK_ERROR);
	}
	if (get_info(map, filename) != CHECK_OK)
	{
		*error_msg = "Error getting map info\n";
		return (CHECK_ERROR);
	}
	if (allocate_map_data(map) != CHECK_OK)
	{
		*error_msg = "Error allocating map data\n";
		return (CHECK_ERROR);
	}
	if (parse_fill(map, filename) != CHECK_OK)
	{
		*error_msg = "Error filling map\n";
		return (CHECK_ERROR);
	}
	return (CHECK_OK);
}

static int	clean_return(int fd, char *line, int return_val)
{
	if (line)
		free(line);
	close(fd);
	return (return_val);
}

int	get_info(t_map *map, char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (CHECK_ERROR);
	line = get_next_line(fd);
	if (line == NULL)
		return (clean_return(fd, NULL, CHECK_ERROR));
	if (get_width(line, &map->width) != CHECK_OK)
		return (clean_return(fd, line, CHECK_ERROR));
	free(line);
	map->height = 1;
	if (get_height(fd, &map->height) != CHECK_OK)
		return (clean_return(fd, line, CHECK_ERROR));
	close(fd);
	return (CHECK_OK);
}

int	parse_fill(t_map *map, char *filename)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (CHECK_ERROR);
	i = 0;
	while (i < map->height)
	{
		line = get_next_line(fd);
		if (line == NULL || parse_line(map, line, i) != CHECK_OK)
		{
			if (line)
				free(line);
			close(fd);
			return (CHECK_ERROR);
		}
		free(line);
		i++;
	}
	close(fd);
	return (CHECK_OK);
}
