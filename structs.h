#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_data			t_data;
typedef struct s_ambient_light	t_ambient_light;
typedef struct s_camera			t_camera;
typedef struct s_light			t_light;
typedef struct s_sphere			t_sphere;
typedef struct s_plane			t_plane;
typedef struct s_cylinder		t_cylinder;
typedef struct s_vector			t_vector;
typedef struct s_space			t_space;
typedef struct s_point			t_point;
typedef struct s_color			t_color;

struct s_vector
{
	float	x;
	float	y;
	float	z;
};

struct s_space
{
	t_vector	x;
	t_vector	y;
	t_vector	z;
};

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
	t_sphere		*sphere_list;
	t_plane			*plane_list;
	t_cylinder		*cylinder_list;
	t_space			camera_space;
	int				color_pixel;
	float			distance; // NULL at -1
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
	t_color	rgb;
};

struct s_camera
{
	float		fov;
	t_point		origin;
	t_vector	vector;
};

struct s_light
{
	float		brightness;
	t_point		origin;
	t_color		rgb;
};

struct s_sphere
{
	float		diameter;
	t_point		center;
	t_color		rgb;
	t_sphere	*next;
};

struct s_plane
{
	t_point		center;
	t_color		rgb;
	t_vector	vector;
	t_plane		*next;
};

struct s_cylinder
{
	float		diameter;
	float		height;
	t_point		center;
	t_color		rgb;
	t_vector	vector;
	t_cylinder	*next;
};

#endif
