/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 19:32:43 by rick              #+#    #+#             */
/*   Updated: 2026/04/01 20:34:51 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = ft_calloc(sizeof(data), 1);
	if (!data)
		return (NULL);
	if (init_mlx(&data) != true)
		return (false);
	return (data);
}

bool	init_camera(t_data *data)
{
	t_camera	*camera;
	t_point		*point;
	t_vector	*vector;

	if (data->camera)
		return (false);
	camera = (t_camera *)ft_calloc(sizeof(t_camera), 1);
	if (!camera)
		return (perror("Malloc fail\n"), false);
	point = (t_point *)ft_calloc(sizeof(t_point), 1);
	if (!point)
		return (perror("Malloc fail\n"), false);
	vector = (t_vector *)ft_calloc(sizeof(t_vector), 1);
	if (!vector)
		return (perror("Malloc fail\n"), false);
	camera->origin = point;
	camera->vector = vector;
	data->camera = camera;
	return (true);
}

bool	init_light(t_data *data)
{
	t_light		*light;
	t_point		*point;
	t_vector	*color;

	if (data->light)
		return (false);
	light = (t_light *)ft_calloc(sizeof(t_light), 1);
	if (!light)
		return (perror("Malloc fail\n"), false);
	point = (t_point *)ft_calloc(sizeof(t_point), 1);
	if (!point)
		return (perror("Malloc fail\n"), false);
	color = (t_color *)ft_calloc(sizeof(t_color), 1);
	if (!color)
		return (perror("Malloc fail\n"), false);
	light->origin = point;
	light->rgb = color;
	data->light = light;
	return (true);
}

bool	init_ambient_light(t_data *data)
{
	t_ambient_light	*ambient;
	t_color			*color;

	if (data->ambient)
		return (false);
	ambient = (t_ambient_light *)ft_calloc(sizeof(t_ambient_light), 1);
	if (!ambient)
		return (perror("Malloc Fail\n"), false);
	color = (t_color *) ft_calloc(sizeof(t_color), 1);
	if (!color)
		return (perror("Malloc Fail\n"), false);
	ambient->rgb = color;
	data->ambient = ambient;
	return (true);
}
