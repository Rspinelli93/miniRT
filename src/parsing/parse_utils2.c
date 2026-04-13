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

/*
* Function to check the format of the file.*/
bool	check_valid_file_type(char *str)
{
	int		len;
	char	*temp;

	len = (int)ft_strlen(str);
	if (len < 4)
		return (false);
	temp = str + (len - 3);
	if (ft_strncmp(temp, ".rt", 4) != 0)
		return (false);
	return (true);
}

bool	parse_ratio_light(float *ratio, char *str)
{
	float	tmp;

	if (is_valid_float(str))
	{
		tmp = ft_atof((const char *)str);
		if (tmp < (float) 0 || tmp > (float) 1)
			return (printf("Error:\nWrong Ratio"), false);
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
			return (printf("Error:\nWrong Dimension"), false);
		*nb = tmp;
	}
	return (true);
}

// they said we should keep 0 and 180 but
// I'm not sure to agree with that
bool	parse_view_range(float *nb, char *str)
{
	float	tmp;

	tmp = ft_atof((const char *)str);
	if (tmp < 0 || tmp > 180)
		return (printf("Error:\nWrong degree of vision\n"), false);
	*nb = tmp;
	return (true);
}
