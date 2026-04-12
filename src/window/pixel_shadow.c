/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_shadow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 14:21:55 by rick              #+#    #+#             */
/*   Updated: 2026/04/12 14:47:36 by rick             ###   ########.fr       */
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
		if (curr_dist < 0)
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
		if (curr_dist < 0)
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
	t_plane		*temp;
	float			curr_dist;

	temp = data->plane_list;
	curr_dist = -1;
	if (!temp)
		return (false);
	while (temp)
	{
		curr_dist = distance_plane(*temp, src, dir);
		if (curr_dist < 0)
			return (true);
		temp = temp->next;
	}
	return (false);
}

bool	check_coaliton(t_data *data, float distance)
{
	t_point		src;
	t_vector	dir;

	src = point_from_cartesien(data->camera->origin, distance, data->dir);
	dir = vector_from_points(src, data->light->origin);
	if (planes_shadow(data, src, dir)
		&& cylinders_shadow(data, src, dir)
		&& spheres_shadow(data, src, dir))
		return (true);
	return (false);
}
