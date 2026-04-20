/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 19:54:20 by rick              #+#    #+#             */
/*   Updated: 2026/04/02 22:22:38 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

/*
* Utility to free and nullify. 
* Passing the address (&ptr) allows us to set the original pointer to NULL.*/
void	free_and_null(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

/*
* Free the allocated arr of str.*/
void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
