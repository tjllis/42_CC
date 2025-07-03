/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:19:16 by tsemenov          #+#    #+#             */
/*   Updated: 2025/06/23 14:10:42 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_move(int keycode, t_fdf *fdf)
{
	if (keycode == LEFT_KEY)
		fdf->move_x -= 10;
	else if (keycode == RIGHT_KEY)
		fdf->move_x += 10;
	else if (keycode == UP_KEY)
		fdf->move_y += 10;
	else if (keycode == DOWN_KEY)
		fdf->move_y -= 10;
}

void	handle_zoom(int keycode, t_fdf *fdf)
{
	if (keycode == PLUS_KEY)
		fdf->zoom *= 1.1f;
	else if (keycode == MINUS_KEY)
		fdf->zoom /= 1.1f;
}

void	handle_rotation(int keycode, t_fdf *fdf)
{
	if (keycode == A_KEY)
		fdf->angle_z += M_PI / 12;
	else if (keycode == D_KEY)
		fdf->angle_z -= M_PI / 12;
}

void	handle_angles(int keycode, t_fdf *fdf)
{
	if (keycode == W_KEY)
		fdf->angle -= M_PI / 30;
	else if (keycode == S_KEY)
		fdf->angle += M_PI / 30;
}

void	handle_scale(int keycode, t_fdf *fdf)
{
	if (keycode == Z_KEY)
		fdf->scale_z += 0.1f;
	else if (keycode == X_KEY)
		fdf->scale_z -= 0.1f;
}
