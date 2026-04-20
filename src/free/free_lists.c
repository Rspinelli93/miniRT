/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 23:40:00 by glucken           #+#    #+#             */
/*   Updated: 2026/04/19 23:40:00 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

static void	free_sphere_list(t_data *data)
{
	t_sphere	*tmp;

	while (data->sphere_list)
	{
		tmp = data->sphere_list->next;
		free(data->sphere_list);
		data->sphere_list = tmp;
	}
}

static void	free_plane_list(t_data *data)
{
	t_plane	*tmp;

	while (data->plane_list)
	{
		tmp = data->plane_list->next;
		free(data->plane_list);
		data->plane_list = tmp;
	}
}

static void	free_cylinder_list(t_data *data)
{
	t_cylinder	*tmp;

	while (data->cylinder_list)
	{
		tmp = data->cylinder_list->next;
		free(data->cylinder_list);
		data->cylinder_list = tmp;
	}
}

static void	free_cone_list(t_data *data)
{
	t_cone	*tmp;

	while (data->cone_list)
	{
		tmp = data->cone_list->next;
		free(data->cone_list);
		data->cone_list = tmp;
	}
}

void	free_objects_lists(t_data *data)
{
	free_sphere_list(data);
	free_plane_list(data);
	free_cylinder_list(data);
	free_cone_list(data);
}
