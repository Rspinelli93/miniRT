# include "minirt.h"

//* TEST FOR WINDOW CREATION
/* int	main(int argc, char **argv)
{
	t_data	data;

	if (validate_args(argc, argv) != true)
		return (false);
	memset_t_data(&data);
	if (init_mlx(&data) != true)
		return (false);
	put_blue_screen(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	setup_hooks(&data);
	mlx_loop(data.mlx);
	return (true);
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
	memset_t_data(&data);
	parse(&data, "./hola.txt");
	//printf("We have an ambient light \n");
	//printf("his ratio is %f", data.ambient->light_ratio);
	//printf("and the rgb values are : %d %d %d \n", data.ambient->r, data.ambient->g, data.ambient->b);
	free_data(&data);
	
	return (0);
}
