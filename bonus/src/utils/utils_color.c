/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:54:34 by glucken           #+#    #+#             */
/*   Updated: 2026/04/13 18:54:34 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

static float	light_tint(float deg, t_light *light, int channel)
{
	if (channel == 0)
		return (deg * light->brightness * light->rgb.r / 255.0f);
	if (channel == 1)
		return (deg * light->brightness * light->rgb.g / 255.0f);
	return (deg * light->brightness * light->rgb.b / 255.0f);
}

static int	clamp_and_hex(t_color *new)
{
	if (new->r > 255)
		new->r = 255;
	if (new->g > 255)
		new->g = 255;
	if (new->b > 255)
		new->b = 255;
	if (new->r < 0)
		new->r = 0;
	if (new->g < 0)
		new->g = 0;
	if (new->b < 0)
		new->b = 0;
	return (get_hex_color(new));
}

/*
* Returns the value of a color in hexadecimal.*/
int	get_hex_color(t_color *rgb)
{
	unsigned int	hex;

	hex = (rgb->r << 16) | (rgb->g << 8) | rgb->b;
	return ((int)hex);
}

int	color_to_shadow(t_data *data, int color)
{
	t_color	new;

	new.r = ((color >> 16) & 0xFF)
		* data->ambient->light_ratio * data->ambient->rgb.r / 255;
	new.g = ((color >> 8) & 0xFF)
		* data->ambient->light_ratio * data->ambient->rgb.g / 255;
	new.b = (color & 0xFF)
		* data->ambient->light_ratio * data->ambient->rgb.b / 255;
	return (clamp_and_hex(&new));
}

int	color_to_light(t_data *data, int color, float angle)
{
	t_color	new;
	float	deg;
	float	light_r;
	float	light_g;
	float	light_b;

	if (angle > (PI / 2))
		return (color_to_shadow(data, color));
	deg = cos(fabsf(angle));
	light_r = light_tint(deg, data->light, 0);
	light_g = light_tint(deg, data->light, 1);
	light_b = light_tint(deg, data->light, 2);
	new.r = ((color >> 16) & 0xFF)
		* (data->ambient->light_ratio * data->ambient->rgb.r / 255 + light_r);
	new.g = ((color >> 8) & 0xFF)
		* (data->ambient->light_ratio * data->ambient->rgb.g / 255 + light_g);
	new.b = (color & 0xFF)
		* (data->ambient->light_ratio * data->ambient->rgb.b / 255 + light_b);
	return (clamp_and_hex(&new));
}
