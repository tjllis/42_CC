/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:18:02 by tsemenov          #+#    #+#             */
/*   Updated: 2025/06/23 12:18:04 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Original map:    3D coordinates:     2D projection:      Wireframe:
// 0 1 0           (0,0,0)(1,0,1)(2,0,0)     
// 1 2 1    →      (0,1,1)(1,1,2)(2,1,1)  →  Screen coords  →  ┌─┬─┐
// 0 1 0           (0,2,0)(1,2,1)(2,2,0)                        ├─┼─┤  
//                                                               └─┴─┘

void	draw_pixel(t_fdf *fdf, int x, int y, int color)
{
	int	position;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	position = (y * fdf->line_len) + (x * (fdf->bits_pp / 8));
	*(int *)(fdf->img_addr + position) = color;
}

int	get_color(t_map *map, int row_y, int col_x)
{
	int	color;

	color = map->points[row_y][col_x].color;
	return (color);
}

void	init_line(t_line *line, t_point2d start, t_point2d end)
{
	line->start_x = start.x;
	line->start_y = start.y;
	line->end_x = end.x;
	line->end_y = end.y;
	line->dist_x = abs(end.x - start.x);
	line->dist_y = abs(end.y - start.y);
	if (start.x < end.x)
		line->step_x = 1;
	else
		line->step_x = -1;
	if (start.y < end.y)
		line->step_y = 1;
	else
		line->step_y = -1;
	line->slope = line->dist_x - line->dist_y;
}

void	draw_loop(t_fdf *fdf, t_line *line, int color)
{
	int	double_slope;

	while (1)
	{
		if (line->start_x == line->end_x && line->start_y == line->end_y)
			break ;
		draw_pixel(fdf, line->start_x, line->start_y, color);
		double_slope = line->slope * 2;
		if (double_slope > -(line->dist_y))
		{
			line->slope -= line->dist_y;
			line->start_x += line->step_x;
		}
		if (double_slope < line->dist_x)
		{
			line->slope += line->dist_x;
			line->start_y += line->step_y;
		}
	}
}

void	draw_line(t_fdf *fdf, t_point2d start, t_point2d end, int color)
{
	t_line	line;

	init_line(&line, start, end);
	draw_loop(fdf, &line, color);
}
