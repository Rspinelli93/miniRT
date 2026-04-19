/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 14:05:00 by rick              #+#    #+#             */
/*   Updated: 2026/04/19 23:35:24 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

void		free_objects_lists(t_data *data);

/*
* Utility to free all allocated memory in data.*/
void	free_data(t_data *data)
{
	if (!data)
		return ;
	free_and_null((void **)&data->ambient);
	free_and_null((void **)&data->camera);
	free_and_null((void **)&data->light);
	free_objects_lists(data);
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
	free_data(data);
	exit(0);
}
