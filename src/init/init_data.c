/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 19:32:24 by rick              #+#    #+#             */
/*   Updated: 2026/04/19 20:13:30 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

void	memset_t_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->img = NULL;
	data->addr = NULL;
	data->bits_per_pixel = 0;
	data->line_length = 0;
	data->endian = 0;
	data->err_num = 0;
	data->ambient = NULL;
	data->camera = NULL;
	data->light = NULL;
	data->sphere_list = NULL;
	data->plane_list = NULL;
	data->cylinder_list = NULL;
	data->color_pixel = -1;
	data->distance = __FLT_MAX__;
}

int	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (false);
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT,
			"Welcome to a Magic World");
	if (!data->win)
		return (false);
	data->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img)
		return (false);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	if (!data->addr)
		return (false);
	return (true);
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
	data->camera_space.x = vectoriel_product(data->camera_space.y,
			data->camera_space.z);
}
