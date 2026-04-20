/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_light_cone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 23:40:00 by glucken           #+#    #+#             */
/*   Updated: 2026/04/19 23:40:00 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

static t_vector	cone_normal(t_cone cone, t_point point)
{
	t_vector	ap;
	t_vector	normal;
	float		radius;
	float		k;
	float		m;

	ap = vector_from_points(cone.apex, point);
	radius = cone.diameter / 2.0f;
	k = (radius * radius) / (cone.height * cone.height);
	m = scalar_product(ap, cone.vector);
	normal.x = ap.x - (1.0f + k) * m * cone.vector.x;
	normal.y = ap.y - (1.0f + k) * m * cone.vector.y;
	normal.z = ap.z - (1.0f + k) * m * cone.vector.z;
	return (normalized(normal));
}

void	put_light_cone(t_data *data, t_cone cone, float curr_dist, int *color)
{
	t_vector	normal;
	t_vector	ray;
	t_point		point;
	float		spec;

	point = point_from_cartesien(data->camera->origin, curr_dist, data->dir);
	normal = cone_normal(cone, point);
	if (scalar_product(normal, data->dir) > 0)
	{
		normal.x = -normal.x;
		normal.y = -normal.y;
		normal.z = -normal.z;
	}
	ray = vector_from_points(point, data->light->origin);
	*color = color_to_light(data, *color, angle_vect(normal, ray));
	spec = phong_specular(data, normal, ray);
	*color = add_white_specular(*color, spec);
}
