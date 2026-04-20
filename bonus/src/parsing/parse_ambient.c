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
* Returns true if the array contains one camera, one ambient
* ligth and one light.*/
bool	check_acl(char **arr)
{
	int	i;
	int	a;
	int	c;
	int	l;

	i = 0;
	a = 0;
	c = 0;
	l = 0;
	while (arr[i])
	{
		if (arr[i][0] == 'A' && arr[i][1] == ' ')
			a++;
		if (arr[i][0] == 'C' && arr[i][1] == ' ')
			c++;
		if (arr[i][0] == 'L' && arr[i][1] == ' ')
			l++;
		i++;
	}
	if (a == 1 && c == 1 && l == 1)
		return (true);
	return (false);
}

/*
* Funtion to parse and set the values in the struct ambient light.
* Returns true on success
* Returns false on failure, in case of malloc fail or
* 		in case that another ambient light was created already
*		during the parsing.*/
bool	parse_ambient_light(t_data *data, char **splitted)
{
	if (init_ambient_light(data) == false)
		return (false);
	if (!(splitted[1] && parse_ratio_light(&(data->ambient->light_ratio),
				splitted[1])))
		return (set_err_num(data, ERR_AMBIENT), false);
	if (!(splitted[2] && parse_rgb(&(data->ambient->rgb.r),
				&(data->ambient->rgb.g), &(data->ambient->rgb.b), splitted[2])))
		return (set_err_num(data, ERR_AMBIENT), false);
	if (splitted[3])
		return (set_err_num(data, ERR_AMBIENT), false);
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
		return (false);
	if (!(splitted[1] && parse_xyz(&(data->camera->origin.x),
				&(data->camera->origin.y), &(data->camera->origin.z),
				splitted[1])))
		return (set_err_num(data, ERR_CAMERA), false);
	if (!(splitted[2] && parse_xyz_norm(&(data->camera->vector.x),
				&(data->camera->vector.y), &(data->camera->vector.z),
				splitted[2])))
		return (set_err_num(data, ERR_CAMERA), false);
	if (!(splitted[3] && parse_view_range(&(data->camera->fov),
				splitted[3])))
		return (set_err_num(data, ERR_CAMERA), false);
	data->camera->fov = data->camera->fov * PI / 180.0f;
	if (splitted[4])
		return (set_err_num(data, ERR_CAMERA), false);
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
		return (false);
	if (!(splitted[1] && parse_xyz(&(data->light->origin.x),
				&(data->light->origin.y),
				&(data->light->origin.z),
				splitted[1])))
		return (set_err_num(data, ERR_LIGHT), false);
	if (!(splitted[2] && parse_ratio_light(&(data->light->brightness),
				splitted[2])))
		return (set_err_num(data, ERR_LIGHT), false);
	if (splitted[3])
	{
		if (!parse_rgb(&(data->light->rgb.r), &(data->light->rgb.g),
				&(data->light->rgb.b), splitted[3]))
			return (set_err_num(data, ERR_LIGHT), false);
		if (splitted[4])
			return (set_err_num(data, ERR_LIGHT), false);
	}
	else
	{
		data->light->rgb.r = 255;
		data->light->rgb.g = 255;
		data->light->rgb.b = 255;
	}
	return (true);
}
