#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include "./gnl/get_next_line.h"
# include "./minilibx_linux/mlx.h"
# include "./libftprintf/libftprintf.h"

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define KEY_ESC 65307
# define SUCCESS 1
# define FAILURE 0

typedef struct s_data			t_data;
typedef struct s_ambient_light	t_ambient_light;
typedef struct s_camera			t_camera;
typedef struct s_light			t_light;
typedef struct s_sphere			t_sphere;
typedef struct s_plane			t_plane;
typedef struct s_cylinder		t_cylinder;
typedef struct s_vector			t_vector;
typedef struct s_point			t_point;
typedef struct s_color			t_color;

struct s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	t_ambient_light	*ambient;
	t_camera		*camera;
	t_light			*light;
	t_list			*sphere_list;
	t_list			*plane_list;
	t_list			*cylinder_list;
};

struct s_vector
{
	float	x;
	float	y;
	float	z;
};

struct s_point
{
	float	x;
	float	y;
	float	z;
};

struct s_color
{
	int	r;
	int	g;
	int	b;
};

struct s_ambient_light
{
	float	light_ratio;
	t_color	*rgb;
};

struct s_camera
{
	int			fov;
	t_point		*origin;
	t_vector	*vector;
};

struct s_light
{
	float		brightness;
	t_point		*origin;
	t_color		*rgb;
};

struct s_sphere
{
	float		diameter;
	t_point		*center;
	t_color		*rgb;
};

struct s_plane
{
	t_point		*center;
	t_color		*rgb;
	t_vector	*vector;
};

struct s_cylinder
{
	float		diameter;
	float		height;
	t_point		*center;
	t_color		*rgb;
	t_vector	*vector;
};

//* ---------- INIT ----------

bool	init_light(t_data *data);
void	memset_t_data(t_data *data);
bool	init_ambient_light(t_data *data);
bool	init_camera(t_data *data);
bool	init_sphere(t_sphere *sphere);
bool	init_plane(t_plane *plane);
bool	init_cylinder(t_cylinder *cylinder);
int		validate_args(int argc, char *argv[]);


//* --------- MINILIBX ---------
int		close_mlx(t_data *data);
void	my_mlx_put_pixel(t_data *data, int x, int y, int color);
int		init_mlx(t_data *data);
void	setup_hooks(t_data *data);
int		put_blue_screen(t_data *data);

//* --------- PARSING ---------
bool	parse(t_data *data, char *doc);
char	**get_text(char *address);

// sub_parsing
int		is_valid_float(const char *str);
double	ft_atof(const char *str);
bool	parse_rgb(int *r, int *g, int *b, char *str);
bool	parse_xyz(float *x, float *y, float *z, char *str);
bool	parse_xyz_norm(float *x, float *y, float *z, char *str);
bool	parse_ratio_light(float *ratio, char *str);
bool	parse_positive_nb(float *nb, char *str);
bool	parse_view_range(int *nb, char *str);
bool	parse_ambient_light(t_data *data, char **splitted);
bool	parse_camera(t_data *data, char **splitted);
bool	parse_light(t_data *data, char **splitted);
bool	parse_sphere(t_data *data, char **splitted);
bool	parse_plane(t_data *data, char **splitted);
bool	parse_cylinder(t_data *data, char **splitted);


//* ---------- FREE ----------

void	free_data(t_data *data);
void	free_split(char **arr);
void	ft_safe_lstdelone(t_list *lst, void (*del)(void **));
void	ft_safe_lstclear(t_list **lst, void (*del)(void **));

#endif
