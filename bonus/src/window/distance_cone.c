/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_cone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 23:40:00 by glucken           #+#    #+#             */
/*   Updated: 2026/04/19 23:40:00 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

static void	cone_abc(t_cone cone, t_vector oc, t_vector dir, float abc[3])
{
	float	radius;
	float	k;

	radius = cone.diameter / 2.0f;
	k = (radius * radius) / (cone.height * cone.height);
	abc[0] = scalar_product(dir, dir)
		- (1.0f + k) * powf(scalar_product(dir, cone.vector), 2.0f);
	abc[1] = 2.0f * (scalar_product(dir, oc)
			- (1.0f + k) * scalar_product(dir, cone.vector)
			* scalar_product(oc, cone.vector));
	abc[2] = scalar_product(oc, oc)
		- (1.0f + k) * powf(scalar_product(oc, cone.vector), 2.0f);
}

static float	check_cone_cap(float sol[2], t_vector dir,
		t_cone cone, t_vector oc)
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
			m = scalar_product(oc, cone.vector)
				+ sol[i] * scalar_product(dir, cone.vector);
			if (m >= 0 && m <= cone.height && (best < 0 || sol[i] < best))
				best = sol[i];
		}
		i++;
	}
	return (best);
}

float	distance_cone(t_cone cone, t_point src, t_vector dir)
{
	t_vector	oc;
	float		abc[3];
	float		sol[2];

	oc = vector_from_points(cone.apex, src);
	cone_abc(cone, oc, dir, abc);
	if (!solve_quadratic(abc[0], abc[1], abc[2], sol))
		return (-1);
	return (check_cone_cap(sol, dir, cone, oc));
}
