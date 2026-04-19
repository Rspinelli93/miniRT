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

bool	parse_rgb(int *r, int *g, int *b, char *str)
{
	char	**s_rgb;
	int		i;
	int		rgb[3];

	s_rgb = ft_split(str, ',');
	if (!s_rgb)
		return (printf("Error\nMalloc Fail\n"), false);
	i = 0;
	while (s_rgb[i] && i < 3)
	{
		if (is_valid_int(s_rgb[i]) && ft_atoi(s_rgb[i]) >= 0
			&& ft_atoi(s_rgb[i]) <= 255)
			rgb[i] = ft_atoi(s_rgb[i]);
		else
			return (free_split(s_rgb), printf("Error\nWrong color code\n"),
				false);
		i++;
	}
	if (i != 3 || s_rgb[i])
		return (free_split(s_rgb), printf("Error\nWrong color code\n"), false);
	free_split(s_rgb);
	*r = rgb[0];
	*g = rgb[1];
	*b = rgb[2];
	return (true);
}

bool	parse_xyz(float *x, float *y, float *z, char *str)
{
	char	**splitted_xyz;
	int		i;
	float	xyz[3];

	splitted_xyz = ft_split(str, ',');
	if (!splitted_xyz)
		return (printf("Error\nMalloc Fail\n"), false);
	i = 0;
	while (splitted_xyz[i] && i < 3)
	{
		if (!is_valid_float(splitted_xyz[i]))
			return (free_split(splitted_xyz), printf("Error\nWrong xyz\n"),
				false);
		xyz[i] = atof(splitted_xyz[i]);
		i++;
	}
	if (splitted_xyz[i] || i < 3)
		return (free_split(splitted_xyz), printf("Error\nWrong xyz\n"), false);
	free_split(splitted_xyz);
	*x = xyz[0];
	*y = xyz[1];
	*z = xyz[2];
	return (true);
}

static void	normalise_xyz(float *x, float *y, float *z)
{
	float	len;

	len = sqrt(*x * *x + *y * *y + *z * *z);
	*x = *x / len;
	*y = *y / len;
	*z = *z / len;
}

bool	parse_xyz_norm(float *x, float *y, float *z, char *str)
{
	char	**splitted_xyz;
	int		i;
	float	xyz[3];

	splitted_xyz = ft_split(str, ',');
	if (!splitted_xyz)
		return (printf("Error\nMalloc Fail\n"), false);
	i = 0;
	while (splitted_xyz[i] && i < 3)
	{
		if (!is_valid_float(splitted_xyz[i]))
			return (free_split(splitted_xyz),
				printf("Error\nNot normalized xyz\n"), false);
		xyz[i] = ft_atof(splitted_xyz[i]);
		i++;
	}
	if (splitted_xyz[i] || i < 3
		|| xyz[0] * xyz[0] + xyz[1] * xyz[1] + xyz[2] * xyz[2] == 0)
		return (free_split(splitted_xyz), printf("Error\nNot normalized xyz\n"),
			false);
	free_split(splitted_xyz);
	*x = xyz[0];
	*y = xyz[1];
	*z = xyz[2];
	return (normalise_xyz(x, y, z), true);
}
