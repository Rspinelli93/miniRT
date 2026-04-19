/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rick <rick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 20:34:48 by rick              #+#    #+#             */
/*   Updated: 2026/04/13 20:34:48 by rick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (printf("Error\nWrong number of args\n"), 1);
	memset_t_data(&data);
	if (!parse(&data, av[1]))
		return (free_data(&data), print_error(data.err_num), 1);
	if (!init_mlx(&data))
		return (printf("Error\nInit mlx\n"), free_data(&data), 2);
	create_space(&data);
	fill_viewport(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	setup_hooks(&data);
	mlx_loop(data.mlx);
	return (free_data(&data), 0);
}

//* Main for running parse tests.
/* int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 3)
		return (printf("Error\nWrong number of args"), 1);
	memset_t_data(&data);
	if (!parse(&data, av[2]))
		return (free_data(&data), print_error(data.err_num), 1);
	return (free_data(&data), 0);
} */
