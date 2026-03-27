/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:27:19 by glucken           #+#    #+#             */
/*   Updated: 2025/10/08 22:30:56 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libftprintf.h"

int	ft_putptr(long long unsigned int ptr)
{
	int	size;

	if (!ptr)
	{
		return (ft_putstr("(nil)"));
	}
	ft_putstr("0x");
	size = ft_putnbr_hexalong(ptr, 1, 2);
	return (size);
}
