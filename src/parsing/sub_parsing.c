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
		{
			if (i == 0)
				*r = tmp;
			if (i == 1)
				*g = tmp;
			if (i == 2)
				*b = tmp;
		}
		else
			return(free(splitted_RGB), perror("Wrong color code\n"), false);
		i++;
	}
	if (i != 3 || splitted_RGB[i])
		return (free(splitted_RGB), perror("Wrong color code\n"), false);
	free(splitted_RGB);
	return (true);
}

bool	parse_ratio_light(float *ratio, char *str)
{
	float	tmp;

	if (is_valid_float(str))
	{
		tmp = ft_atof((const char* ) str);
			if (tmp < (float) 0 || tmp > (float) 1)
				return (perror("Wrong ratio\n"), false);
		*ratio = tmp;
	}
	return(true);
}

bool	parse_ambient_light(t_data *data, char **splitted)
{
	t_ambient_light	*ambient;

	if (data->ambient)
		return (perror("More than one Ambient light"), false);
	ambient = (t_ambient_light *) malloc(sizeof(t_ambient_light));
	if (!ambient)
		return(perror("Malloc Fail \n"), false);
	data->ambient = ambient;
	if (!(splitted[1] && parse_ratio_light(&(data->ambient->light_ratio), splitted[1])))
		return (perror("Error on line 1\n"), false);
	if (!(splitted[2] && parse_RGB(&(data->ambient->r), &(data->ambient->g), &(data->ambient->b), splitted[2])))
		return (perror("Error on line 2\n"), false);
	if (splitted[3])
		return (perror("Error on line 3\n"), false);
	return (true);
}
