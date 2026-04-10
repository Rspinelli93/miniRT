/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 19:18:55 by rick              #+#    #+#             */
/*   Updated: 2026/04/02 22:42:39 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

static t_sphere		*last_sphere(t_sphere *lst);
static t_plane		*last_plane(t_plane *lst);

void	add_back_sphere(t_sphere **lst, t_sphere *new)
{
	t_sphere	*ptr;

	ptr = last_sphere(*lst);
	if (!ptr)
		*lst = new;
	else
		ptr->next = new;
}

static t_sphere	*last_sphere(t_sphere *lst)
{
	t_sphere	*ptr;

	ptr = lst;
	if (!lst)
		return (NULL);
	while (ptr->next != NULL)
		ptr = ptr->next;
	return (ptr);
}

void	add_back_plane(t_plane **lst, t_plane *new)
{
	t_plane	*ptr;

	ptr = last_plane(*lst);
	if (!ptr)
		*lst = new;
	else
		ptr->next = new;
}

static t_plane	*last_plane(t_plane *lst)
{
	t_plane	*ptr;

	ptr = lst;
	if (!lst)
		return (NULL);
	while (ptr->next != NULL)
		ptr = ptr->next;
	return (ptr);
}
