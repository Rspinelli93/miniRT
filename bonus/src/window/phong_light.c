/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 22:44:06 by glucken           #+#    #+#             */
/*   Updated: 2026/04/19 22:44:06 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

int	add_white_specular(int color, float spec)
{
	t_color	new;

	if (spec <= 0.0f)
		return (color);
	if (spec > 1.0f)
		spec = 1.0f;
	new.r = ((color >> 16) & 0xFF) + (int)(255.0f * spec);
	new.g = ((color >> 8) & 0xFF) + (int)(255.0f * spec);
	new.b = (color & 0xFF) + (int)(255.0f * spec);
	if (new.r > 255)
		new.r = 255;
	if (new.g > 255)
		new.g = 255;
	if (new.b > 255)
		new.b = 255;
	return (get_hex_color(&new));
}

float	phong_specular(t_data *data, t_vector normal, t_vector ray)
{
	t_vector	light_dir;
	t_vector	view_dir;
	t_vector	reflect_dir;
	float		dot_nl;
	float		dot_rv;

	light_dir = normalized(ray);
	normal = normalized(normal);
	dot_nl = scalar_product(normal, light_dir);
	if (dot_nl <= 0.0f)
		return (0.0f);
	view_dir.x = -data->dir.x;
	view_dir.y = -data->dir.y;
	view_dir.z = -data->dir.z;
	view_dir = normalized(view_dir);
	reflect_dir.x = 2.0f * dot_nl * normal.x - light_dir.x;
	reflect_dir.y = 2.0f * dot_nl * normal.y - light_dir.y;
	reflect_dir.z = 2.0f * dot_nl * normal.z - light_dir.z;
	reflect_dir = normalized(reflect_dir);
	dot_rv = scalar_product(reflect_dir, view_dir);
	if (dot_rv <= 0.0f)
		return (0.0f);
	return (powf(dot_rv, PHONG) * data->light->brightness * 0.8f);
}
