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

float	distance_plane(t_data *data, t_plane plane)
{
	float	d;
	float	distance;

	d = - plane.vector.x * plane.center.x - plane.vector.y * plane.center.y - plane.vector.z * plane.center.z;
	distance = - d / (plane.vector.x * (data->dir.x + data->camera->origin.x) + plane.vector.y * (data->dir.y + data->camera->origin.y)  + plane.vector.z * (data->dir.z + data->camera->origin.z) );

	return (distance);
}

float	distance_cylinder(t_data *data, t_cylinder cylinder)
{
	(void)data;
	(void)cylinder;

	return(-1);
	// ecrie une fonction pour resoudre une equation de degre 2
	// les 2 solutions sont dans un tableaux
	// on check la derniere condition en z et on resort le plus petit t si il respcte ca
	
}

