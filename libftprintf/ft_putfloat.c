/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 00:00:00 by user              #+#    #+#             */
/*   Updated: 2025/11/24 00:00:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libftprintf.h"

static int	ft_putfloat_integer(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		count += ft_putfloat_integer(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}

static int	ft_putfloat_decimal(double frac, int precision)
{
	int	count;
	int	i;

	count = 0;
	if (precision > 0)
	{
		count += ft_putchar('.');
		i = 0;
		while (i < precision)
		{
			frac *= 10;
			count += ft_putchar((int)frac + '0');
			frac -= (int)frac;
			i++;
		}
	}
	return (count);
}

int	ft_putfloat(double f, int precision)
{
	long	integer_part;
	double	fractional_part;
	int		count;

	count = 0;
	if (precision < 0)
		precision = 6;
	integer_part = (long)f;
	fractional_part = f - integer_part;
	if (fractional_part < 0)
		fractional_part = -fractional_part;
	count += ft_putfloat_integer(integer_part);
	count += ft_putfloat_decimal(fractional_part, precision);
	return (count);
}
