/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:20:29 by tsemenov          #+#    #+#             */
/*   Updated: 2025/06/23 12:20:31 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_center(t_fdf *fdf)
{
	fdf->center_x = (fdf->map->width - 1) / 2.0f;
	fdf->center_y = (fdf->map->height - 1) / 2.0f;
}

int	setup_session(t_fdf *fdf, char **error_msg)
{
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FDF");
	if (fdf->win == NULL)
	{
		*error_msg = "Failed to create window.\n";
		return (CHECK_ERROR);
	}
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (fdf->img == NULL)
	{
		*error_msg = "Failed to create image.\n";
		return (CHECK_ERROR);
	}
	fdf->img_addr = mlx_get_data_addr(fdf->img, \
			&fdf->bits_pp, &fdf->line_len, &fdf->endian);
	if (fdf->img_addr == NULL)
	{
		*error_msg = "Failed to get image address.\n";
		return (CHECK_ERROR);
	}
	fdf->move_x = WIDTH / 2;
	fdf->move_y = HEIGHT / 2;
	set_center(fdf);
	return (CHECK_OK);
}
