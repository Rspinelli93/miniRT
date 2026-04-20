/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 23:40:00 by glucken           #+#    #+#             */
/*   Updated: 2026/04/19 23:40:00 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

static t_cone	*last_cone(t_cone *lst)
{
	t_cone	*ptr;

	ptr = lst;
	if (!lst)
		return (NULL);
	while (ptr->next != NULL)
		ptr = ptr->next;
	return (ptr);
}

void	add_back_cone(t_cone **lst, t_cone *new)
{
	t_cone	*ptr;

	ptr = last_cone(*lst);
	if (!ptr)
		*lst = new;
	else
		ptr->next = new;
}
