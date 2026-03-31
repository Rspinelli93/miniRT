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
	char	**splitted_rgb;
	int		i;
	int		rgb[3];

	splitted_rgb = ft_split(str, ',');
	if (!splitted_rgb)
		return (perror("Malloc Fail\n"), false);
	i = 0;
	while (splitted_rgb[i] && i < 3)
	{
		if (ft_atoi(splitted_rgb[i]) >= 0 && ft_atoi(splitted_rgb[i]) <= 255)
			rgb[i] = ft_atoi(splitted_rgb[i]);
		else
			return (free_split(splitted_rgb), perror("Color code"), false);
		i++;
	}
	if (i != 3 || splitted_rgb[i])
		return (printf("%d", i),free_split(splitted_rgb), perror("Color code"), false);
	free_split(splitted_rgb);
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
		return (perror("Malloc Fail\n"), false);
	i = 0;
	while (splitted_xyz[i] && i < 3)
	{
		if (!is_valid_float(splitted_xyz[i]))
			return (free_split(splitted_xyz), perror("xyz"), false);
		xyz[i] = atof(splitted_xyz[i]);
		i++;
	}
	if (splitted_xyz[i] || i < 3)
		return (free_split(splitted_xyz), perror("xyz"), false);
	free_split(splitted_xyz);
	*x = xyz[0];
	*y = xyz[1];
	*z = xyz[2];
	return (true);
}

bool	parse_xyz_norm(float *x, float *y, float *z, char *str)
{
	char	**splitted_xyz;
	int		i;
	float	xyz[3];

	splitted_xyz = ft_split(str, ',');
	if (!splitted_xyz)
		return (perror("Malloc Fail\n"), false);
	i = 0;
	while (splitted_xyz[i] && i < 3)
	{
		if (!is_valid_float(splitted_xyz[i]))
			return (free_split(splitted_xyz),
				perror("Normalized xyz"), false);
		xyz[i] = ft_atof(splitted_xyz[i]);
		if (xyz[i] < 0 || xyz[i] > 1)
			return (free_split(splitted_xyz), perror("Normalized xyz"), false);
		i++;
	}
	if (splitted_xyz[i] || i < 3)
		return (free_split(splitted_xyz), perror("Normalized xyz"), false);
	free_split(splitted_xyz);
	*x = xyz[0];
	*y = xyz[1];
	*z = xyz[2];
	return (true);
}
