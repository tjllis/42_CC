/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_z.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:20:18 by tsemenov          #+#    #+#             */
/*   Updated: 2025/06/23 12:20:19 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point3d	rotate_z(t_fdf *fdf, t_point3d point3d)
{
	t_point3d	rotated;
	float		cos_z;
	float		sin_z;
	float		x_centered;
	float		y_centered;

	x_centered = point3d.x - fdf->center_x;
	y_centered = point3d.y - fdf->center_y;
	cos_z = cos(fdf->angle_z);
	sin_z = sin(fdf->angle_z);
	rotated.x = x_centered * cos_z - y_centered * sin_z;
	rotated.y = y_centered * cos_z + x_centered * sin_z;
	rotated.z = point3d.z;
	return (rotated);
}
