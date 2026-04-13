/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 19:18:55 by rick              #+#    #+#             */
/*   Updated: 2026/04/12 13:10:26 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

static t_cylinder	*last_cylinder(t_cylinder *lst);

void	add_back_cylinder(t_cylinder **lst, t_cylinder *new)
{
	t_cylinder	*ptr;

	ptr = last_cylinder(*lst);
	if (!ptr)
		*lst = new;
	else
		ptr->next = new;
}

static t_cylinder	*last_cylinder(t_cylinder *lst)
{
	t_cylinder	*ptr;

	ptr = lst;
	if (!lst)
		return (NULL);
	while (ptr->next != NULL)
		ptr = ptr->next;
	return (ptr);
}

/*
* Function to trim new line at the end of the arr of string*/
void	trim_newlines(char **arr)
{
	int	i;
	int	len;

	i = 0;
	while (arr && arr[i])
	{
		len = ft_strlen(arr[i]);
		if (len > 1 && arr[i][len - 1] == '\n')
			arr[i][len - 1] = '\0';
		i++;
	}
}

/*
* Returns the value of a color in hexadecimal.*/
int	get_hex_color(t_color *rgb)
{
	unsigned int	hex;

	hex = (rgb->r << 16) | (rgb->g << 8) | rgb->b;
	return ((int)hex);
}

int	color_to_shadow(int color)
{
	t_color	new;

	new.r = ((color >> 16) & 0xFF) * 0.3;
	new.g = ((color >> 8) & 0xFF) * 0.3;
	new.b = (color & 0xFF) * 0.3;
	if (new.r > 255)
		new.r = 255;
	if (new.g > 255)
		new.g = 255;
	if (new.b > 255)
		new.b = 255;
	if (new.r < 0)
		new.r = 0;
	if (new.g < 0)
		new.g = 0;
	if (new.b < 0)
		new.b = 0;
	return (get_hex_color(&new));
}

int	color_to_light(int color, float angle)
{
	t_color	new;
	float	deg;

	if (angle > (PI/2))
		return (color_to_shadow(color));
	deg = (1.3 - (2 * fabsf(angle) / PI));
	new.r = ((color >> 16) & 0xFF) * deg;
	new.g = ((color >> 8) & 0xFF) * deg;
	new.b = (color & 0xFF) * deg;
	if (new.r > 255)
		new.r = 255;
	if (new.g > 255)
		new.g = 255;
	if (new.b > 255)
		new.b = 255;
	if (new.r < 0)
		new.r = 0;
	if (new.g < 0)
		new.g = 0;
	if (new.b < 0)
		new.b = 0;
	return (get_hex_color(&new));
}

