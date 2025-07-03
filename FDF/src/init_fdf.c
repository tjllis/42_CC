/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:19:22 by tsemenov          #+#    #+#             */
/*   Updated: 2025/06/23 12:19:23 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	map->width = 0;
	map->height = 0;
	map->points = NULL;
	return (map);
}

static void	set_defaults(t_fdf *fdf)
{
	fdf->img = NULL;
	fdf->img_addr = NULL;
	fdf->bits_pp = 32;
	fdf->line_len = 0;
	fdf->endian = 0;
	fdf->zoom = 1.0f;
	fdf->move_x = 0;
	fdf->move_y = 0;
	fdf->angle = M_PI / 6;
	fdf->angle_z = 0.0f;
	fdf->scale_z = 1.0f;
	fdf->center_x = 0.0f;
	fdf->center_y = 0.0f;
}

t_fdf	*init_fdf(void)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		exit_error(NULL, "Memory allocation failed for fdf structure.");
	fdf->mlx = mlx_init();
	if (fdf->mlx == NULL)
		exit_error(fdf, "Failed to initialize MiniLibX.");
	fdf->win = NULL;
	fdf->map = init_map();
	if (fdf->map == NULL)
		exit_error(fdf, "Failed to initialize map structure.");
	set_defaults(fdf);
	return (fdf);
}
