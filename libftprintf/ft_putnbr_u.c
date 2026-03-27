/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:49:20 by glucken           #+#    #+#             */
/*   Updated: 2025/10/11 14:25:41 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libftprintf.h"

int	ft_putnbr_u(unsigned int n, int size)
{
	if (n == 0)
	{
		size += ft_putchar('0');
		return (size);
	}
	if (n >= 10)
		size = ft_putnbr_u(n / 10, size);
	size += ft_putchar('0' + n % 10);
	return (size);
}
