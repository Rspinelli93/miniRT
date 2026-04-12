/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_maths2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 18:51:25 by glucken           #+#    #+#             */
/*   Updated: 2026/04/10 18:51:25 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

bool	solve_quadratic(float a, float b, float c, float sol[2])
{
	float	delta;

	if (a == 0 && b == 0)
		return (false);
	if (a == 0)
	{
		sol[0] = -c / b;
		sol[1] = sol[0];
		return (true);
	}
	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (false);
	sol[0] = (-b - sqrtf(delta)) / (2 * a);
	sol[1] = (-b + sqrtf(delta)) / (2 * a);
	return (true);
}
