/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 14:05:00 by rick              #+#    #+#             */
/*   Updated: 2026/04/02 23:11:57 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

static void	free_cylinder_list(t_data *data);
static void	free_sphere_list(t_data *data);
static void	free_plane_list(t_data *data);

/*
* Utility to free all allocated memory in data.*/
void	free_data(t_data *data)
{
	if (!data)
		return ;
	free_and_null((void **)&data->ambient);
	free_and_null((void **)&data->camera);
	free_and_null((void **)&data->light);
	free_sphere_list(data);
	free_plane_list(data);
	free_cylinder_list(data);
}

/*
* Utility to close cleanly minilibx data.*/
int	close_mlx(t_data *data)
{
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit(true);
}

/*
* Utility to free linked list of spheres.*/
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

/*
* Utility to free linked list of planes.*/
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

/*
* Utility to free linked list of cylinders.*/
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
