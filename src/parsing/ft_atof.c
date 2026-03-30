/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 14:05:55 by glucken           #+#    #+#             */
/*   Updated: 2026/03/30 14:05:55 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

static int	ft_parse_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-')
	{
		sign = -1;
		(*i)++;
	}
	else if (str[*i] == '+')
		(*i)++;
	return (sign);
}

static double	ft_parse_integer(const char *str, int *i)
{
	double	result;

	result = 0.0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		result = result * 10.0 + (str[*i] - '0');
		(*i)++;
	}
	return (result);
}

static double	ft_parse_decimal(const char *str, int *i)
{
	double	decimal_part;
	double	decimal;

	decimal_part = 0.0;
	decimal = 0.1;
	if (str[*i] == '.')
	{
		(*i)++;
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			decimal_part += (str[*i] - '0') * decimal;
			decimal *= 0.1;
			(*i)++;
		}
	}
	return (decimal_part);
}

int	is_valid_float(const char *str)
{
	int	i;
	int	has_dot;

	i = 0;
	has_dot = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '.')
		{
			ft_printf("char: %c\n", str[i]);
			return (false);
		}
		i++;
	}
	i = 0;
	while (str[i++] == '.')
		has_dot += 1;
	if (has_dot > 1)
		return (0);
	return (true);
}

double	ft_atof(const char *str)
{
	double	result;
	double	decimal_part;
	int		sign;
	int		i;

	i = 0;
	sign = ft_parse_sign(str, &i);
	result = ft_parse_integer(str, &i);
	decimal_part = ft_parse_decimal(str, &i);
	return ((result + decimal_part) * sign);
}
