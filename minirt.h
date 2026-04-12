#ifndef MINIRT_H
# define MINIRT_H

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

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define KEY_ESC 65307
# define SUCCESS 1
# define FAILURE 0

//* ---------- INIT ----------
bool	init_light(t_data *data);
void	memset_t_data(t_data *data);
bool	init_ambient_light(t_data *data);
bool	init_camera(t_data *data);
bool	init_sphere(t_sphere *sphere);
bool	init_plane(t_plane *plane);
bool	init_cylinder(t_cylinder *cylinder);
int		validate_args(int argc, char *argv[]);
void	create_space(t_data *data);

//* --------- MINILIBX ---------
int			close_mlx(t_data *data);
void		my_mlx_put_pixel(t_data *data, int x, int y, int color);
int			init_mlx(t_data *data);
void		setup_hooks(t_data *data);

//* --------- WINDOW ----------
void		fill_viewport(t_data *data);
void		set_color_pixel(t_data *data);
float		distance_sphere(t_data *data, t_sphere	sphere);
float		distance_plane(t_data *data, t_plane plane);
float		distance_cylinder(t_data *data, t_cylinder cylinder);
void		put_light_sphere(t_data *data, t_sphere sphere, float curr_dist, int *color);
void		put_light_plane(t_data *data, t_plane plane, float curr_dist, int *color);
void	put_light_cylinder(t_data *data, t_cylinder cyl, float curr_dist, int *color);

//* --------- PARSING ---------
bool		parse(t_data *data, char *doc);
char		**get_text(char *address);
int			is_valid_float(const char *str);
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

//* ---------- FREE ----------
void		free_data(t_data *data);
void		free_and_null(void **ptr);
void		free_split(char **arr);

//* ---------- UTILS ----------
void		add_back_sphere(t_sphere **lst, t_sphere *new);
void		add_back_plane(t_plane **lst, t_plane *new);
void		add_back_cylinder(t_cylinder **lst, t_cylinder *new);
void		trim_newlines(char **arr);
t_vector	vectoriel_product(t_vector a, t_vector b);
float		scalar_product(t_vector a, t_vector b);
float		norm_l2(t_vector a);
float		angle_vect(t_vector a, t_vector b);
t_vector	normalized(t_vector	a);
bool		solve_quadratic(float a, float b, float c, float sol[2]);
t_vector	vector_from_points(t_point a, t_point b);
int			get_hex_color(t_color *rgb);

#endif
