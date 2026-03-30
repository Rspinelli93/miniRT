/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 13:43:30 by glucken           #+#    #+#             */
/*   Updated: 2026/03/30 13:43:30 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

static void	choose_rgb(int *r, int *g, int *b, int tmp, int i)
{
	if (i == 0)
		*r = tmp;
	if (i == 1)
		*g = tmp;
	if (i == 2)
		*b = tmp;
}

static void	choose_xyz(float *x, float *y, float *z, int tmp, int i)
{
	if (i == 0)
		*x = tmp;
	if (i == 1)
		*y = tmp;
	if (i == 2)
		*z = tmp;
}

bool	parse_RGB(int *r, int *g, int *b, char *str)
{
	char **splitted_RGB;
	int	i;
	int tmp;

	splitted_RGB = ft_split(str, ',');
	if (!splitted_RGB)
		return (perror("Malloc Fail\n"), false);
	i = 0;
	while (splitted_RGB[i] && i < 3)
	{
		tmp = ft_atoi(splitted_RGB[i]);
		if (tmp >= 0 && tmp <= 255)
			choose_rgb(r, g, b, tmp, i);
		else
			return(free_split(splitted_RGB), perror("Wrong color code\n"), false);
		i++;
	}
	if (i != 3 || splitted_RGB[i])
		return (free_split(splitted_RGB), perror("Wrong color code\n"), false);
	free_split(splitted_RGB);
	return (true);
}


bool	parse_xyz(float *x, float *y, float *z, char *str)
{
	char	**splitted_xyz;
	int		i;
	float	tmp;

	splitted_xyz = ft_split(str, ',');
	if (!splitted_xyz)
		return (perror("Malloc Fail\n"), false);
	i = 0;
	while (splitted_xyz[i] && i < 3)
	{
		if (!is_valid_float(splitted_xyz[i]))
			return (perror("not a valid float in xyz\n"), false);
		tmp = ft_atof(splitted_xyz[i]);
		choose_xyz(x, y, z, tmp, i);
		i++;
	}
	if (splitted_xyz[i] || i < 3)
		return (perror("Wrong xyz\n"), false);
	return (true);
}

bool	parse_xyz_norm(float *x, float *y, float *z, char *str)
{
	char	**splitted_xyz;
	int		i;
	float	tmp;

	splitted_xyz = ft_split(str, ',');
	if (!splitted_xyz)
		return (perror("Malloc Fail\n"), false);
	i = 0;
	while (splitted_xyz[i] && i < 3)
	{
		if (!is_valid_float(splitted_xyz[i]))
			return (free_split(splitted_xyz), perror("not a valid float in xyz\n"), false);
		tmp = ft_atof(splitted_xyz[i]);
		if (tmp < 0 || tmp > 1)
			return (free_split(splitted_xyz), ("not a valid float in xyz\n"), false);
		choose_xyz(x, y, z, tmp, i);
		i++;
	}
	if (splitted_xyz[i] || i < 3)
		return (free_split(splitted_xyz), perror("Wrong xyz\n"), false);
	free_split(splitted_xyz);
	return (true);
}

