/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:49:20 by glucken           #+#    #+#             */
/*   Updated: 2025/10/11 13:54:55 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libftprintf.h"

static int	ft_printhexabase(int n, int lower)
{
	char	*lower_base;
	char	*upper_base;

	lower_base = "0123456789abcdef";
	upper_base = "0123456789ABCDEF";
	if (lower)
		ft_putchar(lower_base[n]);
	else
		ft_putchar(upper_base[n]);
	return (1);
}

int	ft_putnbr_hexa(unsigned int x, int lower, int size, int flag)
{
	if (flag == '#' && lower == 1)
	{
		size += ft_putstr("0x");
		flag = 0;
	}
	if (flag == '#' && lower == 0)
	{
		size += ft_putstr("0X");
		flag = 0;
	}
	if (x >= 16)
		size = ft_putnbr_hexa(x / 16, lower, size, flag);
	size += ft_printhexabase(x % 16, lower);
	return (size);
}
