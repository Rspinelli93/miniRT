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

bool	parse_sphere(t_data *data, char **splitted)
{
	t_sphere	*sphere;
	t_list		*list;

	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (!sphere)
		return (perror("Malloc Fail\n"), false);
	if (!(splitted[1] && parse_xyz(&(sphere->x), &(sphere->y),
				&(sphere->z), splitted[1])))
		return (printf(" error on Sphere line.\n"), false);
	if (!(splitted[2] && parse_positive_nb(&(sphere->diameter),
				splitted[2])))
		return (printf(" error on Sphere line.\n"), false);
	if (!(splitted[3] && parse_rgb(&(sphere->r), &(sphere->g),
				&(sphere->b), splitted[3])))
		return (false);
	if (splitted[4])
		return (printf(" error on Sphere line: too many arguments.\n"), false);
	list = ft_lstnew(sphere);
	ft_lstadd_back(&(data->sphere_list), list);
	return (true);
}

bool	parse_plane(t_data *data, char **splitted)
{
	t_plane		*plane;
	t_list		*list;

	plane = (t_plane *)malloc(sizeof(t_plane));
	if (!plane)
		return (perror("Malloc Fail\n"), false);
	if (!(splitted[1] && parse_xyz(&(plane->x), &(plane->y),
				&(plane->z), splitted[1])))
		return (printf(" error on Plane line.\n"), false);
	if (!(splitted[2] && parse_xyz_norm(&(plane->x_vector), &(plane->y_vector),
				&(plane->z_vector), splitted[2])))
		return (printf(" error on Plane line.\n"), false);
	if (!(splitted[3] && parse_rgb(&(plane->r), &(plane->g),
				&(plane->b), splitted[3])))
		return (printf(" error on Plane line.\n"), false);
	if (splitted[4])
		return (printf(" error on Plane line: too many arguments.\n"), false);
	list = ft_lstnew(plane);
	ft_lstadd_back(&(data->plane_list), list);
	return (true);
}

bool	parse_cylinder(t_data *data, char **splitted)
{
	t_cylinder	*cylinder;
	t_list		*list;

	cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!cylinder)
		return (perror("Malloc Fail\n"), false);
	if (!(splitted[1] && parse_xyz(&(cylinder->x), &(cylinder->y),
				&(cylinder->z), splitted[1])))
		return (printf(" error on Cylinder line.\n"), false);
	if (!(splitted[2] && parse_xyz_norm(&(cylinder->x_axis), &(cylinder->y_axis),
				&(cylinder->z_axis), splitted[2])))
		return (printf(" error on Cylinder line.\n"), false);
	if (!(splitted[3] && parse_positive_nb(&(cylinder->diameter), splitted[3])))
		return (printf(" error on Cylinder line.\n"), false);
	if (!(splitted[4] && parse_positive_nb(&(cylinder->height), splitted[4])))
		return (printf(" error on Cylinder line.\n"), false);
	if (!(splitted[5] && parse_rgb(&(cylinder->r), &(cylinder->g),
				&(cylinder->b), splitted[5])))
		return (printf(" error on Cylinder line.\n"), false);
	if (splitted[6])
		return (printf(" error on Cylinder line: too many arguments.\n"), false);
	list = ft_lstnew(cylinder);
	ft_lstadd_back(&(data->cylinder_list), list);
	return (true);
}
