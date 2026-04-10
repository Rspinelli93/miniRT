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

/*
* Funtion to parse and set the values in the struct ambient light.
* Returns true on success
* Returns false on failure, in case of malloc fail or
* 		in case that another ambient light was created already
*		during the parsing.*/
bool	parse_ambient_light(t_data *data, char **splitted)
{
	if (init_ambient_light(data) == false)
		return (perror("More than one Ambient light\n"), false);
	if (!(splitted[1] && parse_ratio_light(&(data->ambient->light_ratio),
				splitted[1])))
		return (printf(" error on Ambient Light line.\n"), false);
	if (!(splitted[2] && parse_rgb(&(data->ambient->rgb.r),
				&(data->ambient->rgb.g), &(data->ambient->rgb.b), splitted[2])))
		return (printf(" error on Ambient Light line.\n"), false);
	if (splitted[3])
	{
		printf(" error on Ambient Light line: too many args.\n");
		return (false);
	}
	return (true);
}

/*
* Funtion to parse and set the values in the struct camera.
* Returns true on success
* Returns false on failure, in case of malloc fail or
* 		in case that another camera was created already
*		during the parsing.*/
bool	parse_camera(t_data *data, char **splitted)
{
	if (init_camera(data) == false)
		return (perror("More than one Camera\n"), false);
	if (!(splitted[1] && parse_xyz(&(data->camera->origin.x),
				&(data->camera->origin.y), &(data->camera->origin.z),
				splitted[1])))
		return (printf(" error on Camera line.\n"), false);
	if (!(splitted[2] && parse_xyz_norm(&(data->camera->vector.x),
				&(data->camera->vector.y), &(data->camera->vector.z),
				splitted[2])))
		return (printf(" error on Camera line.\n"), false);
	if (!(splitted[3] && parse_view_range(&(data->camera->fov),
				splitted[3])))
		return (printf(" error on Camera line.\n"), false);
	data->camera->fov = data->camera->fov * M_PI / 180.0f;
	if (splitted[4])
		return (printf(" error on Camera line: too many args.\n"), false);
	return (true);
}

/*
* Funtion to parse and set the values in the struct light.
* Returns true on success
* Returns false on failure, in case of malloc fail or
* 		in case that another light was created already
*		during the parsing.*/
bool	parse_light(t_data *data, char **splitted)
{
	if (init_light(data) == false)
		return (perror("More than one Light.\n"), false);
	if (!(splitted[1] && parse_xyz(&(data->light->origin.x),
				&(data->light->origin.y),
				&(data->light->origin.z),
				splitted[1])))
		return (printf(" error on Light line.\n"), false);
	if (!(splitted[2] && parse_ratio_light(&(data->light->brightness),
				splitted[2])))
		return (printf(" error on Light line.\n"), false);
	if (!(splitted[3] && parse_rgb(&(data->light->rgb.r), &(data->light->rgb.g),
				&(data->light->rgb.b), splitted[3])))
		return (printf(" error on Light line.\n"), false);
	if (splitted[4])
		return (printf("too many arguments error on Light line.\n"), false);
	return (true);
}
