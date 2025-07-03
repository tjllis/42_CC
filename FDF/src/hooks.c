/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:19:06 by tsemenov          #+#    #+#             */
/*   Updated: 2025/06/23 12:19:07 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_win(t_fdf *fdf)
{
	clean_exit(fdf);
	return (0);
}

int	handle_keys(int keycode, t_fdf *fdf)
{
	if (keycode == ESC_KEY)
		clean_exit(fdf);
	else if (keycode == LEFT_KEY || keycode == RIGHT_KEY || \
				keycode == UP_KEY || keycode == DOWN_KEY)
		handle_move(keycode, fdf);
	else if (keycode == W_KEY || keycode == S_KEY)
		handle_angles(keycode, fdf);
	else if (keycode == A_KEY || keycode == D_KEY)
		handle_rotation(keycode, fdf);
	else if (keycode == Z_KEY || keycode == X_KEY)
		handle_scale(keycode, fdf);
	else if (keycode == PLUS_KEY || keycode == MINUS_KEY)
		handle_zoom(keycode, fdf);
	draw_map(fdf);
	return (0);
}

void	set_hooks(t_fdf *fdf)
{
	mlx_key_hook(fdf->win, handle_keys, fdf);
	mlx_hook(fdf->win, 17, 0, close_win, fdf);
}
