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
	t_list 		*list;

	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (!sphere)
		return (perror("Malloc Fail\n"), false);
	if (!(splitted[1] && parse_xyz(&(sphere->x), &(sphere->y),
				&(sphere->z), splitted[1])))
		return (false);
	if (!(splitted[2] && parse_positive_nb(&(sphere->diameter),
				splitted[2])))
		return (false);
	if (!(splitted[3] && parse_rgb(&(sphere->r), &(sphere->g),
				&(sphere->b), splitted[3])))
		return (false);
	if (splitted[3])
		return (false);
	list = ft_lstnew(sphere);
	ft_lstadd_back(&(data->sphere_list), list);
	return (true);
}
