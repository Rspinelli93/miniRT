/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 20:27:38 by glucken           #+#    #+#             */
/*   Updated: 2026/03/30 20:27:38 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

bool	parse_ambient_light(t_data *data, char **splitted)
{
	t_ambient_light	*ambient;

	if (data->ambient)
		return (perror("More than one Ambient light\n"), false);
	ambient = (t_ambient_light *) malloc(sizeof(t_ambient_light));
	if (!ambient)
		return (perror("Malloc Fail\n"), false);
	data->ambient = ambient;
	if (!(splitted[1] && parse_ratio_light(&(data->ambient->light_ratio),
				splitted[1])))
		return (false);
	if (!(splitted[2] && parse_rgb(&(data->ambient->r), &(data->ambient->g),
				&(data->ambient->b), splitted[2])))
		return (false);
	if (splitted[3])
		return (false);
	return (true);
}

bool	parse_camera(t_data *data, char **splitted)
{
	t_camera	*camera;

	if (data->camera)
		return (perror("More than one Camera\n"), false);
	camera = (t_camera *)malloc(sizeof(t_camera));
	if (!camera)
		return (perror("Malloc fail\n"), false);
	data->camera = camera;
	if (!(splitted[1] && parse_xyz(&(data->camera->x), &(data->camera->y),
				&(data->camera->z), splitted[1])))
		return (false);
	if (!(splitted[2] && parse_xyz_norm(&(data->camera->x_orientation),
				&(data->camera->y_orientation), &(data->camera->z_orientation),
				splitted[2])))
		return (false);
	if (!(splitted[3] && parse_view_range(&(data->camera->fov), splitted[3])))
		return (false);
	if (splitted[4])
		return (false);
	return (true);
}

bool	parse_light(t_data *data, char **splitted)
{
	t_light	*light;

	if (data->light)
		return (perror("More than one Light\n"), false);
	light = (t_light *) malloc(sizeof(t_light));
	if (!light)
		return (perror("Malloc Fail\n"), false);
	data->light = light;
	if (!(splitted[1] && parse_xyz(&(data->light->x), &(data->light->y),
				&(data->light->z), splitted[1])))
		return (false);
	if (!(splitted[2] && parse_ratio_light(&(data->light->brightness),
				splitted[2])))
		return (false);
	if (!(splitted[3] && parse_rgb(&(data->light->r), &(data->light->g),
				&(data->light->b), splitted[3])))
		return (false);
	if (splitted[3])
		return (false);
	return (true);
}
