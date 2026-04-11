/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 19:02:20 by rick              #+#    #+#             */
/*   Updated: 2026/04/10 19:04:27 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

static void	send_vector(t_data *data, int x, int y);

/*
* Function to fill our viewport that then will be pushed to the Window.*/
void	fill_viewport(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			send_vector(data, x, y);
			my_mlx_put_pixel(data, x, y, data->color_pixel);
			data->color_pixel = -1;
			data->distance = __FLT_MAX__;
			x++;
		}
		y++;
	}
}

void	 create_normalized_director(t_data *data, int x, int y)
{
	float		vpx;
	float		vpy;
	float		h;

	h = tan(data->camera->fov / 2.0f);
	vpx = (2.0f * ((float)x + 0.5f) / WIN_WIDTH - 1.0f)
		* (float)WIN_WIDTH / (float)WIN_HEIGHT * h;
	vpy = (1.0f - 2.0f * ((float)y + 0.5f) / WIN_HEIGHT) * h;
	data->dir.x = vpx * data->camera_space.x.x + vpy * data->camera_space.y.x + data->camera_space.z.x;
	data->dir.y = vpx * data->camera_space.x.y + vpy * data->camera_space.y.y + data->camera_space.z.y;
	data->dir.z = vpx * data->camera_space.x.z + vpy * data->camera_space.y.z + data->camera_space.z.z;
	data->dir = normalized(data->dir);
}
/* 
* Casts a ray and runs set_color_pixel to set the color of that current pixel
* In the struct t_data.*/
static void	send_vector(t_data *data, int x, int y)
{
	create_normalized_director(data, x, y);
	set_color_pixel(data);
}
