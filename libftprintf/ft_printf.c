/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:57:35 by glucken           #+#    #+#             */
/*   Updated: 2025/10/11 13:36:17 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libftprintf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		size;

	va_start(args, str);
	size = parseur(str, &args);
	va_end(args);
	return (size);
}
