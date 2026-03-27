/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glucken <glucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:27:19 by glucken           #+#    #+#             */
/*   Updated: 2025/10/11 14:25:49 by glucken          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libftprintf.h"

int	parseur(const char *str, va_list *args)
{
	int	i;
	int	size;
	int	flag;

	i = 0;
	size = 0;
	flag = 0;
	while (str[i] != 0)
	{
		if (str[i] == '%')
		{
			if (str[i + 1] != 0 && is_in(str[i + 1], "# +"))
			{
				flag = str[i++ + 1];
			}
			if (str[i + 1] != 0 && is_in(str[i + 1], "cspdiuxX%f"))
				size += ft_printarg(str[i++ + 1], args, flag);
		}
		else
			size += ft_putchar(str[i]);
		i++;
	}
	return (size);
}
