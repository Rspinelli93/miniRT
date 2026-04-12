/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 18:49:43 by rick              #+#    #+#             */
/*   Updated: 2026/04/12 13:46:54 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

static void	check_planes(t_data *data, int *color, t_point src, t_vector dir);
static void	check_spheres(t_data *data, int *color, t_point src, t_vector dir);
static void	check_cylinders(t_data *data, int *color, t_point src, t_vector dir);

/*
* Function to change the value of the color of the current pixel in data.
* We initialize the color to the background color and we check if the ray
* Collides with any type of object.
* In that case we compare the distances and we change the value of color accordingly.
*/
void	set_color_pixel(t_data *data)
{
	int	color;

	color = get_hex_color(&(data->ambient->rgb));
	check_spheres(data, &color, data->camera->origin, data->dir);
	check_planes(data, &color, data->camera->origin, data->dir);
	check_cylinders(data, &color, data->camera->origin, data->dir);
	data->color_pixel = color;
}

/*
* This function will iterate on the sphere list and check on the
* Current pixel if the ray makes contact with it.
* In that case, the function will change the color value accordingly.*/
static void	check_spheres(t_data *data, int *color, t_point src, t_vector dir)
{
	t_sphere		*temp;
	float			curr_dist;

	temp = data->sphere_list;
	curr_dist = -1;
	if (!temp)
		return ;
	while (temp)
	{
		curr_dist = distance_sphere(*temp, src, dir);
		if (curr_dist < data->distance && curr_dist > 0)
		{
			*color = get_hex_color(&(temp->rgb));
			put_light_sphere(data, *temp, curr_dist, color);
			data->distance = curr_dist;
		}
		temp = temp->next;
	}
}

/*
* This function will iterate on the cylinder list and check on the
* Current pixel if the ray makes contact with it.
* In that case, the function will change the color value accordingly.*/
static void	check_cylinders(t_data *data, int *color, t_point src, t_vector dir)
{
	t_cylinder		*temp;
	float			curr_dist;

	temp = data->cylinder_list;
	curr_dist = -1;
	if (!temp)
		return ;
	while (temp)
	{
		curr_dist = distance_cylinder(*temp, src, dir);
		if (curr_dist < data->distance && curr_dist > 0)
		{
			*color = get_hex_color(&(temp->rgb));
			put_light_cylinder(data, *temp, curr_dist, color);
			data->distance = curr_dist;
		}
		temp = temp->next;
	}
}

/*
* This function will iterate on the plane list and check on the
* Current pixel if the ray makes contact with it.
* In that case, the function will change the color value accordingly.*/
static void	check_planes(t_data *data, int *color, t_point src, t_vector dir)
{
	t_plane		*temp;
	float		curr_dist;

	temp = data->plane_list;
	curr_dist = -1;
	if (!temp)
		return ;
	while (temp)
	{
		curr_dist = distance_plane(*temp, src, dir);
		if (curr_dist < data->distance && curr_dist > 0)
		{
			*color = get_hex_color(&(temp->rgb));
			put_light_plane(data, *temp, curr_dist, color);
			data->distance = curr_dist;
		}
		temp = temp->next;
	}
}
