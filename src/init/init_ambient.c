/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ambient.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 19:32:43 by rick              #+#    #+#             */
/*   Updated: 2026/04/19 21:31:17 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

/*
* Function to initializate the camera struct.
* This function will be a helper also for the parser
* Returning NULL if it already exists a camera and 
* Therefore failing the parser test.*/
bool	init_camera(t_data *data)
{
	t_camera	*camera;

	if (data->camera)
		return (set_err_num(data, ERR_DUPLICATE), false);
	camera = (t_camera *)ft_calloc(sizeof(t_camera), 1);
	if (!camera)
		return (set_err_num(data, ERR_MALLOC), false);
	data->camera = camera;
	return (true);
}

/*
* Function to initializate the light struct.
* This function will be a helper also for the parser
* Returning NULL if it already exists a light and 
* Therefore failing the parser test.*/
bool	init_light(t_data *data)
{
	t_light		*light;

	if (data->light)
		return (set_err_num(data, ERR_DUPLICATE), false);
	light = (t_light *)ft_calloc(sizeof(t_light), 1);
	if (!light)
		return (set_err_num(data, ERR_MALLOC), false);
	data->light = light;
	return (true);
}

/*
* Function to initializate the ambient_light struct.
* This function will be a helper also for the parser
* Returning NULL if it already exists a ambient_light and 
* Therefore failing the parser test.*/
bool	init_ambient_light(t_data *data)
{
	t_ambient_light	*ambient;

	if (data->ambient)
		return (set_err_num(data, ERR_DUPLICATE), false);
	ambient = (t_ambient_light *)ft_calloc(sizeof(t_ambient_light), 1);
	if (!ambient)
		return (set_err_num(data, ERR_MALLOC), false);
	data->ambient = ambient;
	return (true);
}
