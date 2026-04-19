/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 09:57:44 by glucken           #+#    #+#             */
/*   Updated: 2026/04/12 09:57:44 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_point	point_from_cartesien(t_point origin, float curr_dist, t_vector	dir)
{
	t_point	point;

	point.x = origin.x + curr_dist * dir.x;
	point.y = origin.y + curr_dist * dir.y;
	point.z = origin.z + curr_dist * dir.z;
	return (point);
}

void	put_light_sphere(t_data *data, t_sphere sphere,
			float curr_dist, int *color)
{
	t_vector	normal;
	t_vector	ray;
	t_point		point;

	point = point_from_cartesien(data->camera->origin, curr_dist, data->dir);
	normal = vector_from_points(sphere.center, point);
	if (scalar_product(data->dir, normal) > 0)
	{
		*color = color_to_shadow(data, *color);
		return ;
	}
	ray = vector_from_points(point, data->light->origin);
	*color = color_to_light(data, *color, angle_vect(normal, ray));
}

void	put_light_plane(t_data *data, t_plane plane,
			float curr_dist, int *color)
{
	t_vector	normal;
	t_vector	ray;
	t_point		point;

	point = point_from_cartesien(data->camera->origin, curr_dist, data->dir);
	normal = plane.vector;
	ray = vector_from_points(point, data->light->origin);
	if (scalar_product(normal, data->dir) > 0)
	{
		normal.x = -normal.x;
		normal.y = -normal.y;
		normal.z = -normal.z;
	}
	*color = color_to_light(data, *color, angle_vect(normal, ray));
}

void	put_light_cylinder(t_data *data, t_cylinder cyl, float curr_dist,
		int *color)
{
	t_vector	normal;
	t_vector	ray;
	t_point		point;
	float		m;

	point = point_from_cartesien(data->camera->origin, curr_dist, data->dir);
	m = scalar_product(data->dir, cyl.vector) * curr_dist
		+ scalar_product(vector_from_points(cyl.center,
				data->camera->origin), cyl.vector);
	normal.x = (point.x - cyl.center.x) - m * cyl.vector.x;
	normal.y = (point.y - cyl.center.y) - m * cyl.vector.y;
	normal.z = (point.z - cyl.center.z) - m * cyl.vector.z;
	normal = normalized(normal);
	ray = vector_from_points(point, data->light->origin);
	*color = color_to_light(data, *color, angle_vect(normal, ray));
}
