/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_shadow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 14:21:55 by rick              #+#    #+#             */
/*   Updated: 2026/04/19 23:35:24 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

/*
* This function will iterate on the sphere list and check on the
* current pixel position if there is a coaliton in the light direction.
* In that case, the function will change the color value accordingly
* adding a shadow afterwards.*/
static bool	spheres_shadow(t_data *data, t_point src, t_vector dir)
{
	t_sphere		*temp;
	float			curr_dist;

	temp = data->sphere_list;
	curr_dist = -1;
	if (!temp)
		return (false);
	while (temp)
	{
		curr_dist = distance_sphere(*temp, src, dir);
		if (curr_dist > 0.001 && curr_dist
			< norm_l2(vector_from_points(data->light->origin, src)))
			return (true);
		temp = temp->next;
	}
	return (false);
}

/*
* This function will iterate on the cylinder list and check on the
* current pixel position if there is a coaliton in the light direction.
* In that case, the function will change the color value accordingly
* adding a shadow afterwards.*/
static bool	cylinders_shadow(t_data *data, t_point src, t_vector dir)
{
	t_cylinder		*temp;
	float			curr_dist;

	temp = data->cylinder_list;
	curr_dist = -1;
	if (!temp)
		return (false);
	while (temp)
	{
		curr_dist = distance_cylinder(*temp, src, dir);
		if (curr_dist > 0.001 && curr_dist
			< norm_l2(vector_from_points(data->light->origin, src)))
			return (true);
		temp = temp->next;
	}
	return (false);
}

/*
* This function will iterate on the plane list and check on the
* current pixel position if there is a coaliton in the light direction.
* In that case, the function will change the color value accordingly
* adding a shadow afterwards.*/
static bool	planes_shadow(t_data *data, t_point src, t_vector dir)
{
	t_plane	*temp;
	float	curr_dist;

	temp = data->plane_list;
	curr_dist = -1;
	if (!temp)
		return (false);
	while (temp)
	{
		curr_dist = distance_plane(*temp, src, dir);
		if (curr_dist > 0.001 && curr_dist
			< norm_l2(vector_from_points(data->light->origin, src)))
			return (true);
		temp = temp->next;
	}
	return (false);
}

static bool	cones_shadow(t_data *data, t_point src, t_vector dir)
{
	t_cone	*temp;
	float	curr_dist;

	temp = data->cone_list;
	curr_dist = -1;
	if (!temp)
		return (false);
	while (temp)
	{
		curr_dist = distance_cone(*temp, src, dir);
		if (curr_dist > 0.001 && curr_dist
			< norm_l2(vector_from_points(data->light->origin, src)))
			return (true);
		temp = temp->next;
	}
	return (false);
}

bool	check_coalition(t_data *data, float distance)
{
	t_point		src;
	t_vector	dir;

	src = point_from_cartesien(data->camera->origin, distance, data->dir);
	dir = vector_from_points(src, data->light->origin);
	dir = normalized(dir);
	src.x += dir.x * 0.01f;
	src.y += dir.y * 0.01f;
	src.z += dir.z * 0.01f;
	if (planes_shadow(data, src, dir)
		|| cylinders_shadow(data, src, dir)
		|| spheres_shadow(data, src, dir)
		|| cones_shadow(data, src, dir))
		return (true);
	return (false);
}
