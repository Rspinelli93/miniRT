/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shapes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 20:32:37 by rick              #+#    #+#             */
/*   Updated: 2026/04/01 22:00:49 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	init_sphere(t_sphere *sphere)
{
	t_point		*center;
	t_color		*color;

	sphere = (t_sphere *)ft_calloc(sizeof(t_sphere), 1);
	if (!sphere)
		return (perror("Malloc Fail\n"), false);
	center = (t_point *)ft_calloc(sizeof(t_point), 1);
	if (!center)
		return (perror("Malloc fail\n"), false);
	color = (t_color *)ft_calloc(sizeof(t_color), 1);
	if (!color)
		return (perror("Malloc fail\n"), false);
	sphere->center = center;
	sphere->rgb = color;
	return (true);
}

bool	init_plane(t_plane *plane)
{
	t_plane		*plane;
	t_point		*center;
	t_color		*color;
	t_vector	*vector;

	plane = (t_plane *)ft_calloc(sizeof(t_plane), 1);
	if (!plane)
		return (perror("Malloc Fail\n"), false);
	center = (t_point *)ft_calloc(sizeof(t_point), 1);
	if (!center)
		return (perror("Malloc fail\n"), false);
	color = (t_color *)ft_calloc(sizeof(t_color), 1);
	if (!color)
		return (perror("Malloc fail\n"), false);
	vector = (t_vector *)ft_calloc(sizeof(t_vector), 1);
	if (!vector)
		return (perror("Malloc fail\n"), false);
	plane->center = center;
	plane->rgb = color;
	plane->vector = vector;
	return (true);
}

bool	init_cylinder(t_cylinder *cylinder)
{
	t_cylinder	*cylinder;
	t_point		*center;
	t_color		*color;
	t_vector	*vector;

	cylinder = (t_cylinder *)ft_calloc(sizeof(t_cylinder), 1);
	if (!cylinder)
		return (perror("Malloc Fail\n"), false);
	center = (t_point *)ft_calloc(sizeof(t_point), 1);
	if (!center)
		return (perror("Malloc fail\n"), false);
	color = (t_color *)ft_calloc(sizeof(t_color), 1);
	if (!color)
		return (perror("Malloc fail\n"), false);
	vector = (t_vector *)ft_calloc(sizeof(t_vector), 1);
	if (!vector)
		return (perror("Malloc fail\n"), false);
	cylinder->center = center;
	cylinder->rgb = color;
	cylinder->vector = vector;
	return (true);
}
