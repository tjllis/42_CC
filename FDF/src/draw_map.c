/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:18:14 by tsemenov          #+#    #+#             */
/*   Updated: 2025/06/23 12:18:51 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_connections(t_fdf *fdf, int row_y, int col_x)
{
	t_point2d	start;
	t_point2d	end;
	int			color;

	start = get_point2d(fdf, row_y, col_x);
	color = get_color(fdf->map, row_y, col_x);
	if (col_x < fdf->map->width - 1)
	{
		end = get_point2d(fdf, row_y, col_x + 1);
		draw_line(fdf, start, end, color);
	}
	if (row_y < fdf->map->height - 1)
	{
		end = get_point2d(fdf, row_y + 1, col_x);
		draw_line(fdf, start, end, color);
	}
}

void	draw_map(t_fdf *fdf)
{
	int			row_y;
	int			col_x;

	ft_memset(fdf->img_addr, 0, WIDTH * HEIGHT * (fdf->bits_pp / 8));
	row_y = 0;
	while (row_y < fdf->map->height)
	{
		col_x = 0;
		while (col_x < fdf->map->width)
		{
			draw_connections(fdf, row_y, col_x);
			col_x++;
		}
		row_y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
