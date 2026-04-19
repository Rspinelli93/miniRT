/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 19:18:55 by rick              #+#    #+#             */
/*   Updated: 2026/04/19 22:03:33 by rick             ###   ########.fr       */
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

void	print_error(int err_num)
{
	if (err_num == 0)
		return ;
	if (err_num == 1)
		printf("Error\nMalloc Fail\n");
	if (err_num == 2)
		printf("Error\nLine should start with A, C, L, sp, pl or cy.\n");
	if (err_num == 3)
		printf("Error\nFile must have only one Camera, Ambient L or Light\n");
	if (err_num == 4)
		printf("Error\nWrong Ambient Light line.\n");
	if (err_num == 5)
		printf("Error\nWrong Camera line.\n");
	if (err_num == 6)
		printf("Error\nWrong Ligth line.\n");
	if (err_num == 7)
		printf("Error\nWrong Sphere line.\n");
	if (err_num == 8)
		printf("Error\nWrong Plane line.\n");
	if (err_num == 9)
		printf("Error\nWrong Cylinder line.\n");
}

void	set_err_num(t_data *data, int num)
{
	data->err_num = num;
}
