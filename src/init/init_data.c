/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 19:32:24 by rick              #+#    #+#             */
/*   Updated: 2026/04/13 18:44:52 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = ft_calloc(sizeof(data), 1);
	if (!data)
		return (NULL);
	if (init_mlx(data) != true)
		return (false);
	return (data);
}

void	memset_t_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->img = NULL;
	data->addr = NULL;
	data->bits_per_pixel = 0;
	data->line_length = 0;
	data->endian = 0;
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
		return (printf("MLX INIT FAIL\n"), false);
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT,
			"Welcome to a Magic World");
	if (!data->win)
		return (printf("NEW WIN FAIL\n"), false);
	data->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img)
		return (printf("NEW IMG FAIL\n"), false);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	if (!data->addr)
		return (printf("GET ADDR FAIL\n"), false);
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
