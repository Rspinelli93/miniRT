/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 19:18:55 by rick              #+#    #+#             */
/*   Updated: 2026/04/10 18:58:48 by rick             ###   ########.fr       */
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
