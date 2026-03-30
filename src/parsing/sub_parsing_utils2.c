/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_parsing_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 20:26:44 by glucken           #+#    #+#             */
/*   Updated: 2026/03/30 20:26:44 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

bool	parse_ratio_light(float *ratio, char *str)
{
	float	tmp;

	if (is_valid_float(str))
	{
		tmp = ft_atof((const char *)str);
		if (tmp < (float) 0 || tmp > (float) 1)
			return (perror("Wrong ratio\n"), false);
		*ratio = tmp;
	}
	return (true);
}

bool	parse_positive_nb(float *nb, char *str)
{
	float	tmp;

	if (is_valid_float(str))
	{
		tmp = ft_atof((const char *)str);
		if (tmp < (float) 0)
			return (perror("Wrong dimension\n"), false);
		*nb = tmp;
	}
	return (true);
}

// they said we should keep 0 and 180 but
// I'm not sure to agree with that
bool	parse_view_range(int *nb, char *str)
{
	int	tmp;

	tmp = ft_atof((const char *)str);
	if (tmp < (int) 0 || tmp > 180)
		return (perror("Wrong degree of vision\n"), false);
	*nb = tmp;
	return (true);
}
