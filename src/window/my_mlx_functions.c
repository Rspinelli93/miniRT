/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 19:19:37 by rick              #+#    #+#             */
/*   Updated: 2026/04/02 19:19:37 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

void	my_mlx_put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int	key_event(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		close_mlx(data);
	return (0);
}

void	setup_hooks(t_data *data)
{
	mlx_hook(data->win, 17, 0, close_mlx, data);
	mlx_key_hook(data->win, key_event, data);
}

bool	is_touching_sphere(t_data *data, float vpx, float vpy)
{
	t_vector	dir;
	t_vector	oc;
	float		radius;
	float		disc;

	dir.x = vpx * data->camera_space.x.x + vpy * data->camera_space.y.x + data->camera_space.z.x;
	dir.y = vpx * data->camera_space.x.y + vpy * data->camera_space.y.y + data->camera_space.z.y;
	dir.z = vpx * data->camera_space.x.z + vpy * data->camera_space.y.z + data->camera_space.z.z;
	dir = normalized(dir);
	oc.x = data->camera->origin.x - data->sphere_list->center.x;
	oc.y = data->camera->origin.y - data->sphere_list->center.y;
	oc.z = data->camera->origin.z - data->sphere_list->center.z;
	radius = data->sphere_list->diameter / 2.0f;
	disc = pow(scalar_product(dir, oc), 2)
		- (scalar_product(oc, oc) - radius * radius);
	return (disc >= 0);
}

/*
* Function to change the value of the color of the current pixel in data.*/
int	send_vector(t_data *data, int x, int y)
{
	float	vpx;
	float	vpy;
	float	h;
	int		color;

	h = tan(data->camera->fov / 2.0f);
	vpx = (2.0f * ((float)x + 0.5f) / WIN_WIDTH - 1.0f)
		* (float)WIN_WIDTH / (float)WIN_HEIGHT * h;
	vpy = (1.0f - 2.0f * ((float)y + 0.5f) / WIN_HEIGHT) * h;
	if (is_touching_sphere(data, vpx, vpy))
		color = 0x0000FF;
	else
		color = 0xFFFFFF;
	return (color);
}

/*
* Set up function to create our 3D space.*/
void	create_space(t_data *data)
{
	t_vector	up;

	up.x = 1;
	up.y = 0;
	up.z = 0;
	data->camera_space.z = data->camera->vector;
	data->camera_space.y = vectoriel_product(data->camera->vector, up);
	data->camera_space.x = vectoriel_product(data->camera_space.y, data->camera_space.z);
}

/*
* Function to fill our canvas that then will be pushed to the Window.*/
int	put_blue_screen(t_data *data)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			color = send_vector(data, x, y);
			my_mlx_put_pixel(data, x, y, color);
			//set color and distance back to -1
			x++;
		}
		y++;
	}
	return (true);
}
