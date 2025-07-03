/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_env.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:08:46 by tsemenov          #+#    #+#             */
/*   Updated: 2025/06/23 12:08:48 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_ENV_H
# define FDF_ENV_H

# include <stdlib.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include "../libs/minilibx-linux/mlx.h"
# include "../libs/libft/includes/libft.h"
# include "../libs/libft/includes/get_next_line.h"
# include "../libs/libft/includes/ft_printf.h"

# define WIDTH 1920
# define HEIGHT 1080

# define ANGLE_30 0.523599

# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define RED 0xE80C0C
# define GREEN 0x00FF00
# define PURPLE 0x9933FF
# define PINK 0xFF0066

# define ESC_KEY	65307
# define W_KEY		119
# define A_KEY		97
# define S_KEY		115
# define D_KEY		100
# define Z_KEY		122
# define X_KEY		120
# define PLUS_KEY	61
# define MINUS_KEY	45
# define LEFT_KEY	65361
# define RIGHT_KEY	65363
# define UP_KEY		65362
# define DOWN_KEY	65364

# define CHECK_OK 1
# define CHECK_ERROR 0

typedef struct s_point {
	int	z;
	int	color;
	int	has_color;
}	t_point;

typedef struct s_map {
	int		width;
	int		height;
	t_point	**points;
}	t_map;

typedef struct s_point2d
{
	int	x;
	int	y;
}	t_point2d;

typedef struct s_point3d
{
	float	x;
	float	y;
	float	z;
}	t_point3d;

typedef struct s_line
{
	int	start_x;
	int	start_y;
	int	end_x;
	int	end_y;
	int	step_x;
	int	step_y;
	int	slope;
	int	dist_x;
	int	dist_y;
}	t_line;

typedef struct s_fdf {
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_addr;
	t_map	*map;
	float	zoom;
	int		bits_pp;
	int		line_len;
	int		endian;
	int		move_x;
	int		move_y;
	float	angle;
	float	angle_z;
	float	scale_z;
	float	center_x;
	float	center_y;
}	t_fdf;

// typedef struct s_coord {
//     int x;
//     int y;
// } t_coord;

#endif
