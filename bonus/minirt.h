/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 20:38:33 by rick              #+#    #+#             */
/*   Updated: 2026/04/13 20:38:33 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define PI 3.14159265358979323846
# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define KEY_ESC 65307
# define SUCCESS 1
# define FAILURE 0
# define PHONG 16

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stdio.h>
# include "structs.h"
# include "./libft/libft.h"
# include "./gnl/get_next_line.h"
# include "./minilibx_linux/mlx.h"

//* ---------- INIT ----------
bool		init_light(t_data *data);
void		memset_t_data(t_data *data);
bool		init_ambient_light(t_data *data);
bool		init_camera(t_data *data);
void		create_space(t_data *data);

//* --------- MINILIBX ---------
void		my_mlx_put_pixel(t_data *data, int x, int y, int color);
int			init_mlx(t_data *data);
void		setup_hooks(t_data *data);

//* --------- WINDOW ----------
void		fill_viewport(t_data *data);
void		set_color_pixel(t_data *data);
float		distance_sphere(t_sphere sphere, t_point src, t_vector dir);
float		distance_plane(t_plane plane, t_point src, t_vector dir);
float		distance_cylinder(t_cylinder cylinder, t_point src, t_vector dir);
float		distance_cone(t_cone cone, t_point src, t_vector dir);
void		put_light_sphere(t_data *data, t_sphere sphere,
				float curr_dist, int *color);
void		put_light_plane(t_data *data, t_plane plane,
				float curr_dist, int *color);
void		put_light_cylinder(t_data *data, t_cylinder cyl,
				float curr_dist, int *color);
void		put_light_cone(t_data *data, t_cone cone,
				float curr_dist, int *color);
int			add_white_specular(int color, float spec);
float		phong_specular(t_data *data, t_vector normal, t_vector ray);

//* -------- PARSING --------
bool		parse(t_data *data, char *doc);
int			is_valid_float(const char *str);
bool		is_valid_int(const char *str);
double		ft_atof(const char *str);
bool		parse_rgb(int *r, int *g, int *b, char *str);
bool		parse_xyz(float *x, float *y, float *z, char *str);
bool		parse_xyz_norm(float *x, float *y, float *z, char *str);
bool		parse_ratio_light(float *ratio, char *str);
bool		parse_positive_nb(float *nb, char *str);
bool		parse_view_range(float *nb, char *str);
bool		parse_ambient_light(t_data *data, char **splitted);
bool		parse_camera(t_data *data, char **splitted);
bool		parse_light(t_data *data, char **splitted);
bool		parse_sphere(t_data *data, char **splitted);
bool		parse_plane(t_data *data, char **splitted);
bool		parse_cylinder(t_data *data, char **splitted);
bool		parse_cone(t_data *data, char **splitted);
bool		check_acl(char **arr);
bool		check_valid_file_type(char *str);
void		print_error(int err_num);

//* ---------- FREE ----------
void		free_data(t_data *data);
void		free_and_null(void **ptr);
void		free_split(char **arr);
int			close_mlx(t_data *data);

//* ---------- UTILS ----------
void		add_back_sphere(t_sphere **lst, t_sphere *new);
void		add_back_plane(t_plane **lst, t_plane *new);
void		add_back_cylinder(t_cylinder **lst, t_cylinder *new);
void		add_back_cone(t_cone **lst, t_cone *new);
void		trim_newlines(char **arr);
t_vector	vectoriel_product(t_vector a, t_vector b);
float		scalar_product(t_vector a, t_vector b);
float		norm_l2(t_vector a);
float		angle_vect(t_vector a, t_vector b);
t_vector	normalized(t_vector	a);
bool		solve_quadratic(float a, float b, float c, float sol[2]);
t_vector	vector_from_points(t_point a, t_point b);
t_point		point_from_cartesien(t_point origin,
				float curr_dist, t_vector	dir);
void		set_err_num(t_data *data, int num);

//* ---------- RAY ----------
int			get_hex_color(t_color *rgb);
int			color_to_shadow(t_data *data, int color);
int			color_to_light(t_data *data, int color, float angle);
bool		check_coalition(t_data *data, float distance);

#endif
