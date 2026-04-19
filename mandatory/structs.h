/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 20:38:39 by rick              #+#    #+#             */
/*   Updated: 2026/04/19 22:05:19 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

typedef enum e_err
{
	ERR_NONE,
	ERR_MALLOC,
	ERR_INVALID_ID,
	ERR_DUPLICATE,
	ERR_AMBIENT,
	ERR_CAMERA,
	ERR_LIGHT,
	ERR_SPHERE,
	ERR_PLANE,
	ERR_CYLINDER
}	t_err;

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
	int				err_num;
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
	float			distance;
	t_vector		dir;
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
