# include "minirt.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (validate_args(argc, argv) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	memset_t_data(&data);
	if (init_mlx(&data) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	put_blue_screen(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	setup_hooks(&data);
	mlx_loop(data.mlx);
	return (EXIT_SUCCESS);
}
