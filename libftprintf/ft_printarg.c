/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:27:19 by glucken           #+#    #+#             */
/*   Updated: 2025/10/11 14:20:50 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libftprintf.h"

int	ft_printarg(const char c, va_list *args, int flag)
{
	int	size;

	size = 0;
	if (c == '%')
		size += ft_putchar('%');
	if (c == 'c')
		size += ft_putchar(va_arg(*args, int));
	if (c == 'd')
		size += ft_putnbr(va_arg(*args, int), 0, flag);
	if (c == 'i')
		size += ft_putnbr(va_arg(*args, int), 0, flag);
	if (c == 'p')
		size += ft_putptr(va_arg(*args, long long unsigned int));
	if (c == 's')
		size += ft_putstr(va_arg(*args, char *));
	if (c == 'u')
		size += ft_putnbr_u(va_arg(*args, unsigned int), 0);
	if (c == 'x')
		size += ft_putnbr_hexa(va_arg(*args, unsigned int), 1, 0, flag);
	if (c == 'X')
		size += ft_putnbr_hexa(va_arg(*args, unsigned int), 0, 0, flag);
	if (c == 'f')
		size += ft_putfloat(va_arg(*args, double), 6);
	return (size);
}
