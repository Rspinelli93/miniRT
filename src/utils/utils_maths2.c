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

int	*solve_2_equation(int a, int b, int c)
{
	int sol[2];
	int delta;

	if (a == 0 && b == 0)
		return (NULL);
	if (a == 0)
	{
		sol[0] = - c / b;
		sol[1] = - c / b;
		return (sol);
	}
	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (NULL);
	else
	{
		sol[0] = (- b - sqrt(delta)) / (2 * a);
		sol[1] = (- b + sqrt(delta)) / (2 * a);
	}
	return (sol);
}
