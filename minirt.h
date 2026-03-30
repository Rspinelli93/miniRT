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
	t_sphere		*sphere;
	t_plane			*plane;
	t_cylinder		*cylinder;
};

struct s_ambient_light
{
	float	light_ratio; //between 0 and 1
	int		r; //between 0 and 255
	int		g; //between 0 and 255
	int		b; //between 0 and 255
};

struct s_camera
{
	int		fov;
	float	x; //also negative, from where to where?
	float	y;
	float	z;
	float	x_orientation; //between -1 and 1
	float	y_orientation; //between -1 and 1
	float	z_orientation; //between -1 and 1
};

struct s_light
{
	float	x; //also negative, from where to where?
	float	y;
	float	z;
	float	brightness; //between 0 and 1
	int		r; //between 0 and 255 BONUS
	int		g; //between 0 and 255
	int		b; //between 0 and 255
};

struct s_sphere
{
	float		x; //also negative, from where to where?
	float		y;
	float		z;
	float		diameter; //between 0 and 1
	int			r; //between 0 and 255 BONUS
	int			g; //between 0 and 255
	int			b; //between 0 and 255
	t_sphere	*next;
};

struct s_plane
{
	float		x; //also negative, from where to where?
	float		y; //coordenates of the center
	float		z;
	float		x_vector; //between -1 and 1
	float		y_vector; //between -1 and 1
	float		z_vector; //between -1 and 1
	int			r; //between 0 and 255 BONUS
	int			g; //between 0 and 255
	int			b; //between 0 and 255
	t_plane		*next;
};

struct s_cylinder
{
	float		x; //also negative, from where to where?
	float		y; //coordenates of the center
	float		z;
	float		diameter;
	float		height;
	int			r; //between 0 and 255 BONUS
	int			g; //between 0 and 255
	int			b; //between 0 and 255
	float		x_axis; //between -1 and 1
	float		y_axis; //between -1 and 1
	float		z_axis; //between -1 and 1
	t_cylinder	*next;
};

void	memset_t_data(t_data *data);
int		validate_args(int argc, char *argv[]);
void	free_split(char **arr);

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
bool	parse_RGB(int *r, int *g, int *b, char *str);
bool	parse_xyz(float *x, float *y, float *z, char *str);
bool	parse_xyz_norm(float *x, float *y, float *z, char *str);
bool	parse_ratio_light(float *ratio, char *str);
bool	parse_positive_nb(float *nb, char *str);
bool	parse_view_range(int *nb, char *str);
bool	parse_ambient_light(t_data *data, char **splitted);
bool	parse_camera(t_data *data, char **splitted);
bool	parse_light(t_data *data, char **splitted);


#endif
