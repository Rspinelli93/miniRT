/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 19:32:43 by rick              #+#    #+#             */
/*   Updated: 2026/03/30 15:44:15 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = ft_calloc(sizeof(data), 1);
	if (!data)
		return (NULL);
	if (init_mlx(&data) != true)
		return (false);
	return (data);
}

