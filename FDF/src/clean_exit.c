/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:17:52 by tsemenov          #+#    #+#             */
/*   Updated: 2025/06/23 12:17:55 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_matrix(char **arr)
{
	int	i;

	if (arr == NULL)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	delete_map(t_map *map)
{
	int	i;

	if (map->points)
	{
		i = 0;
		while (i < map->height)
		{
			if (map->points[i] != NULL)
				free(map->points[i]);
			i++;
		}
		free(map->points);
		map->points = NULL;
	}
	map->width = 0;
	map->height = 0;
	free(map);
}

void	delete_fdf(t_fdf *fdf)
{
	if (fdf == NULL)
		return ;
	if (fdf->img)
	{
		mlx_destroy_image(fdf->mlx, fdf->img);
		fdf->img = NULL;
		fdf->img_addr = NULL;
	}
	if (fdf->win)
	{
		mlx_destroy_window(fdf->mlx, fdf->win);
		fdf->win = NULL;
	}
	if (fdf->map)
	{
		delete_map(fdf->map);
		fdf->map = NULL;
	}
	if (fdf->mlx)
	{
		mlx_destroy_display(fdf->mlx);
		free(fdf->mlx);
		fdf->mlx = NULL;
	}
	free(fdf);
}

void	clean_exit(t_fdf *fdf)
{
	if (fdf)
		delete_fdf(fdf);
	clean_after_gnl();
	exit(EXIT_SUCCESS);
}

void	exit_error(t_fdf *fdf, char *message)
{
	if (fdf)
		delete_fdf(fdf);
	clean_after_gnl();
	if (message)
		ft_putstr_fd(message, 2);
	exit(EXIT_FAILURE);
}
