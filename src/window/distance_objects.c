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

float	distance_plane(t_data *data, t_plane plane, t_vector dir)
{
	float	d;
	float	distance;

	d = - plane.vector.x * plane.center.x - plane.vector.y * plane.center.y - plane.vector.z * plane.center.z;
	distance = -d / (plane.vector.x * dir.x + plane.vector.y * dir.y + plane.vector.z * dir.z);

	return (distance);
}

float	distance_cyclinder(t_data *data, t_cylinder cylinder, t_vector dir)
{
	// ecrie une fonction pour resoudre une equation de degre 2
	// les 2 solutions snt dans un ableaux
	// on check la derniere condition en z et on resort le plus petit t si il respcte ca
	
}


