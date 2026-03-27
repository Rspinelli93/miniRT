/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 19:32:43 by rick              #+#    #+#             */
/*   Updated: 2026/03/27 21:24:10 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = ft_calloc(sizeof(data), 1);
	if (!data)
		return (NULL);
	if (init_mlx(&data) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (data);
}

