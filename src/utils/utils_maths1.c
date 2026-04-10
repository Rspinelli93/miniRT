/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_maths1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 15:48:24 by glucken           #+#    #+#             */
/*   Updated: 2026/04/07 15:48:24 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_vector	vectoriel_product(t_vector a, t_vector b)
{
	t_vector	result;

	result.x = a.y * b.z - a.z * b.y;
	result.y = a.z * b.x - a.x * b.z;
	result.z = a.x * b.y - a.y * b.x;
	return (result);
}

float	scalar_product(t_vector a, t_vector b)
{
	float	result;

	result = a.x * b.x + a.y * b.y + a.z * b.z;
	return (result);
}

float	norm_l2(t_vector a)
{
	float result;

	result = sqrt(scalar_product(a, a));
	return (result);
}

// checker le cas ou on fait une division par 0
float	angle(t_vector a, t_vector b)
{
	float result;

	result = acos(scalar_product(a, b)/(norm_l2(a) * norm_l2(b)));
	return (result);
}

t_vector	normalized(t_vector a)
{
	float		norm;
	t_vector	result;

	norm = norm_l2(a);
	if (norm == 0)
	{
		result.x = 0;
		result.y = 0;
		result.z = 0;
	}
	else
	{
		result.x = a.x / norm;
		result.y = a.y / norm;
		result.z = a.z / norm;
	}
	return (result);
}

