/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_objects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 18:19:39 by glucken           #+#    #+#             */
/*   Updated: 2026/04/10 18:19:39 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

float	distance_sphere(t_data *data, t_sphere	sphere)
{
	t_vector	oc;
	float		radius;
	float		delta;

	oc.x = data->camera->origin.x - sphere.center.x;
	oc.y = data->camera->origin.y - sphere.center.y;
	oc.z = data->camera->origin.z - sphere.center.z;
	radius = sphere.diameter / 2.0f;
	delta = pow(scalar_product(data->dir, oc), 2)
		- (scalar_product(oc, oc) - radius * radius);
	if (delta > 0)
		return (1);
	return (-1);
}
// ici il faudrait encore renvoyer la distance et pas 1

float	distance_plane(t_data *data, t_plane plane)
{
	float	denom;
	float	t;
	t_vector	oc;

	denom = scalar_product(plane.vector, data->dir);
	if (denom > -1e-6 && denom < 1e-6)
		return (-1);
	oc.x = plane.center.x - data->camera->origin.x;
	oc.y = plane.center.y - data->camera->origin.y;
	oc.z = plane.center.z - data->camera->origin.z;
	t = scalar_product(oc, plane.vector) / denom;
	if (t > 0)
		return (t);
	return (-1);
}

static float	check_cylinder_cap(float sol[2], t_data *data, t_cylinder cyl, t_vector oc)
{
	float	m;
	int		i;
	float	best;

	best = -1;
	i = 0;
	while (i < 2)
	{
		if (sol[i] > 0)
		{
			m = scalar_product(data->dir, cyl.vector) * sol[i]
				+ scalar_product(oc, cyl.vector);
			if (m >= 0 && m <= cyl.height
				&& (best < 0 || sol[i] < best))
				best = sol[i];
		}
		i++;
	}
	return (best);
}

float	distance_cylinder(t_data *data, t_cylinder cylinder)
{
	t_vector	oc;
	float		a;
	float		b;
	float		c;
	float		sol[2];

	oc.x = data->camera->origin.x - cylinder.center.x;
	oc.y = data->camera->origin.y - cylinder.center.y;
	oc.z = data->camera->origin.z - cylinder.center.z;
	a = scalar_product(data->dir, data->dir)
		- pow(scalar_product(data->dir, cylinder.vector), 2);
	b = 2 * (scalar_product(data->dir, oc)
			- scalar_product(data->dir, cylinder.vector)
			* scalar_product(oc, cylinder.vector));
	c = scalar_product(oc, oc)
		- pow(scalar_product(oc, cylinder.vector), 2)
		- pow(cylinder.diameter / 2.0f, 2);
	if (!solve_quadratic(a, b, c, sol))
		return (-1);
	return (check_cylinder_cap(sol, data, cylinder, oc));
}

