/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 14:05:00 by rick              #+#    #+#             */
/*   Updated: 2026/03/30 21:31:14 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

/*
+ Free the allocated arr of str.*/
void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	safe_free(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	free_data(t_data *data)
{
	safe_free((void **)&(data->ambient));
	safe_free((void **)&(data->camera));
	safe_free((void **)&(data->light));
	ft_safe_lstclear(&(data->sphere_list), safe_free);
	ft_safe_lstclear(&(data->plane_list), safe_free);
	ft_safe_lstclear(&(data->cylinder_list), safe_free);
}
