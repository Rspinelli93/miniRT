/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 19:19:37 by rick              #+#    #+#             */
/*   Updated: 2026/04/02 19:19:37 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

void	my_mlx_put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int	key_event(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		close_mlx(data);
	return (0);
}

static int	expose_event(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

void	setup_hooks(t_data *data)
{
	mlx_hook(data->win, 17, 0, close_mlx, data);
	mlx_key_hook(data->win, key_event, data);
	mlx_expose_hook(data->win, expose_event, data);
}
