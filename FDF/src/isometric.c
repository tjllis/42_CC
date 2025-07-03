/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:19:31 by tsemenov          #+#    #+#             */
/*   Updated: 2025/06/23 12:19:32 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point3d	create_point3d(t_map *map, int row_y, int col_x)
{
	t_point3d	point3d;

	point3d.x = (float)col_x;
	point3d.y = (float)row_y;
	point3d.z = map->points[row_y][col_x].z;
	return (point3d);
}

t_point2d	make_isometric(t_fdf *fdf, t_point3d point3d)
{
	t_point2d	point2d;
	t_point3d	rotated;
	float		x_iso;
	float		y_iso;

	rotated = rotate_z(fdf, point3d);
	rotated.x *= fdf->zoom;
	rotated.y *= fdf->zoom;
	rotated.z *= fdf->zoom * fdf->scale_z;
	x_iso = (rotated.x - rotated.y) * cos(fdf->angle);
	y_iso = (rotated.x + rotated.y) * sin(fdf->angle) - rotated.z * 0.5;
	point2d.x = (int)x_iso + fdf->move_x;
	point2d.y = (int)y_iso + fdf->move_y;
	return (point2d);
}

t_point2d	get_point2d(t_fdf *fdf, int row_y, int col_x)
{
	t_point3d	point3d;
	t_point2d	point2d;

	point3d = create_point3d(fdf->map, row_y, col_x);
	point2d = make_isometric(fdf, point3d);
	return (point2d);
}
