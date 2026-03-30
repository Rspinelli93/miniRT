# include "minirt.h"

//* TEST FOR WINDOW CREATION
/* int	main(int argc, char **argv)
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
 */

// *TEST FOR GET_TEXT
/* int	main(void)
{
	int i = 0;
	char **arr;

	arr = get_text("./hola.txt");
	if (!arr)
		return (0);
	while (arr[i])
	{
		printf("%s", arr[i]);
		i++;
	}
	return (0);
} */

int main(void)
{
	t_data data;
	parse(&data, "./hola.txt");
	return (0);
}