/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:18:58 by tsemenov          #+#    #+#             */
/*   Updated: 2025/06/23 12:19:00 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*fdf;
	char	*error_msg;

	if (argc != 2)
		exit_error(NULL, "No <map.fdf>\n");
	fdf = init_fdf();
	if (fdf == NULL)
		exit_error(NULL, "Failed to create FDF structure.\n");
	error_msg = NULL;
	if (parse_map(fdf->map, argv[1], &error_msg) != CHECK_OK)
		exit_error(fdf, error_msg);
	if (setup_session(fdf, &error_msg) != CHECK_OK)
		exit_error(fdf, error_msg);
	draw_map(fdf);
	set_hooks(fdf);
	mlx_loop(fdf->mlx);
	clean_exit(fdf);
	return (0);
}
