/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:08:39 by tsemenov          #+#    #+#             */
/*   Updated: 2025/06/23 12:08:41 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "fdf_env.h"

// checks.c
int			is_fdf(char *filename);
int			is_valid_int(char *str);
int			is_valid_color(char *str);
// clean_exit.c
void		delete_map(t_map *map);
void		delete_fdf(t_fdf *fdf);
void		clean_exit(t_fdf *fdf);
void		exit_error(t_fdf *fdf, char *message);
void		free_matrix(char **arr);
// draw.c
void		draw_map(t_fdf *fdf);
//draw_helpers.c
void		draw_pixel(t_fdf *fdf, int x, int y, int color);
int			get_color(t_map *map, int row_y, int col_x);
void		init_line(t_line *line, t_point2d start, t_point2d end);
void		draw_loop(t_fdf *fdf, t_line *line, int color);
void		draw_line(t_fdf *fdf, t_point2d start, t_point2d end, int color);
// hooks.c
int			close_win(t_fdf *fdf);
int			handle_keys(int keycode, t_fdf *fdf);
void		set_hooks(t_fdf *fdf);
// hooks_utils.c
void		handle_move(int keycode, t_fdf *fdf);
void		handle_zoom(int keycode, t_fdf *fdf);
void		handle_rotation(int keycode, t_fdf *fdf);
void		handle_angles(int keycode, t_fdf *fdf);
void		handle_scale(int keycode, t_fdf *fdf);
// init_fdf.c
t_map		*init_map(void);
t_fdf		*init_fdf(void);
// isometric.c
t_point3d	create_point3d(t_map *map, int row_y, int col_x);
t_point2d	make_isometric(t_fdf *fdf, t_point3d point3d);
t_point2d	get_point2d(t_fdf *fdf, int row_y, int col_x);
// parse_map.c
int			parse_map(t_map *map, char *filename, char **error_msg);
int			get_info(t_map *map, char *filename);
int			parse_fill(t_map *map, char *filename);
// parse_mem.c
int			allocate_rows(t_map *map);
int			allocate_map_data(t_map *map);
// parse_point.c
void		init_point(t_point *point);
int			parse_point(char *str, t_point *point);
int			parse_point_simple(char *str, t_point *point);
int			parse_point_color(char *str, t_point *point);
// parse_utils.c
int			get_width(char *line, int *width);
int			get_height(int fd, int *height);
int			parse_line(t_map *map, char *line, int row);
int			is_valid_width(char **split, int width);
int			fill_row(t_map *map, char **split, int row);
// rotate.c
t_point3d	rotate_z(t_fdf *fdf, t_point3d point3d);
// setup_env.c
// int	count_default_zoom(t_map *map);
// float	calc_default_zoom(t_fdf *fdf);
int			setup_session(t_fdf *fdf, char **error_msg);
void		set_center(t_fdf *fdf);

#endif
