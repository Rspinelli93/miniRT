/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_parsing2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 09:11:22 by glucken           #+#    #+#             */
/*   Updated: 2026/03/31 09:11:22 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

/*
* Funtion to parse and set the values in the struct sphere.
* Returns true on success, adding the newly allocated struct
*		to the linked list in data.
* Returns false on failure, in case of malloc fail.*/
bool	parse_sphere(t_data *data, char **splitted)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)ft_calloc(sizeof(t_sphere), 1);
	if (!sphere)
		return (printf("Error\nMalloc Fail\n"), false);
	if (!(splitted[1] && parse_xyz(&(sphere->center.x), &(sphere->center.y),
				&(sphere->center.z), splitted[1])))
		return (free(sphere), printf("Error\nWrong Sphere line.\n"), false);
	if (!(splitted[2] && parse_positive_nb(&(sphere->diameter),
				splitted[2])))
		return (free(sphere), printf("Error\nWrong Sphere line.\n"), false);
	if (!(splitted[3] && parse_rgb(&(sphere->rgb.r), &(sphere->rgb.g),
				&(sphere->rgb.b), splitted[3])))
		return (free(sphere), printf("Error\nWrong Sphere line.\n"), false);
	if (splitted[4])
		return (free(sphere), printf("Error\nSphere: too many args.\n"), false);
	add_back_sphere(&(data->sphere_list), sphere);
	return (true);
}

/*
* Funtion to parse and set the values in the struct plane.
* Returns true on success, adding the newly allocated struct
*		to the linked list in data.
* Returns false on failure, in case of malloc fail.*/
bool	parse_plane(t_data *data, char **splitted)
{
	t_plane	*plane;

	plane = (t_plane *)ft_calloc(sizeof(t_plane), 1);
	if (!plane)
		return (printf("Error\nMalloc Fail\n"), false);
	if (!(splitted[1] && parse_xyz(&(plane->center.x), &(plane->center.y),
				&(plane->center.z), splitted[1])))
		return (free(plane), printf("Error\nWrong Plane line.\n"), false);
	if (!(splitted[2] && parse_xyz_norm(&(plane->vector.x), &(plane->vector.y),
				&(plane->vector.z), splitted[2])))
		return (free(plane), printf("Error\nWrong Plane line.\n"), false);
	if (!(splitted[3] && parse_rgb(&(plane->rgb.r), &(plane->rgb.g),
				&(plane->rgb.b), splitted[3])))
		return (free(plane), printf("Error\nWrong Plane line.\n"), false);
	if (splitted[4])
		return (free(plane), printf("Error\nPlane: too many args.\n"), false);
	add_back_plane(&(data->plane_list), plane);
	return (true);
}

/*
* Funtion to parse and set the values in the struct cylinder.
* Returns true on success, adding the newly allocated struct
*		to the linked list in data.
* Returns false on failure, in case of malloc fail.*/
bool	parse_cylinder(t_data *data, char **splitted)
{
	t_cylinder	*cy;

	cy = (t_cylinder *)ft_calloc(sizeof(t_cylinder), 1);
	if (!cy)
		return (printf("Error\nMalloc Fail\n"), false);
	if (!(splitted[1] && parse_xyz(&(cy->center.x), &(cy->center.y),
				&(cy->center.z), splitted[1])))
		return (free(cy), printf("Error\nWrong Cylinder line.\n"), false);
	if (!(splitted[2] && parse_xyz_norm(&(cy->vector.x),
				&(cy->vector.y), &(cy->vector.z), splitted[2])))
		return (free(cy), printf("Error\nWrong Cylinder line.\n"), false);
	if (!(splitted[3] && parse_positive_nb(&(cy->diameter), splitted[3])))
		return (free(cy), printf("Error\nWrong Cylinder line.\n"), false);
	if (!(splitted[4] && parse_positive_nb(&(cy->height), splitted[4])))
		return (free(cy), printf("Error\nWrong Cylinder line.\n"), false);
	if (!(splitted[5] && parse_rgb(&(cy->rgb.r), &(cy->rgb.g),
				&(cy->rgb.b), splitted[5])))
		return (free(cy), printf("Error\nWrong Cylinder line.\n"), false);
	if (splitted[6])
		return (free(cy), printf("Error\nCylinder: too many args.\n"), false);
	add_back_cylinder(&(data->cylinder_list), cy);
	return (true);
}
