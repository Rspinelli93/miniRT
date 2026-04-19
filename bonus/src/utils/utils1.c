/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 19:18:55 by rick              #+#    #+#             */
/*   Updated: 2026/04/19 23:35:24 by glucken          ###   ########.fr       */
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
	int	j;

	i = 0;
	while (arr && arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == '\t' || arr[i][j] == '\r')
				arr[i][j] = ' ';
			j++;
		}
		len = ft_strlen(arr[i]);
		while (len > 0 && arr[i][len - 1] == '\n')
			arr[i][--len] = '\0';
		while (len > 0 && arr[i][len - 1] == ' ')
			arr[i][--len] = '\0';
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
		printf("Error\nLine should start with A, C, L, sp, pl, cy or co.\n");
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
	if (err_num == 10)
		printf("Error\nWrong Cone line.\n");
}

void	set_err_num(t_data *data, int num)
{
	data->err_num = num;
}
