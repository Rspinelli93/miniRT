# include "minirt.h"

//* TEST FOR WINDOW CREATION
int	main()
{
	t_data	data;

	memset_t_data(&data);
	if (init_mlx(&data) != true)
		return (false);
	//* ADD TO PARSER EVEX TIME WE USE ATOF (IF THE NUMBER IS NOT EQUAL TO FTOA(ATOF("NUM")))
	if (!parse(&data, "./board.rt"))
		return (printf("parse err"), 1);
	create_space(&data);
	fill_viewport(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	setup_hooks(&data);
	mlx_loop(data.mlx);
	return (true);
}


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

/*
int main(void)
{
	t_data	data;

	memset_t_data(&data);
	if (!parse(&data, "./hola.rt"))
		return (printf("parse err"), 1);
	//printf("We have an ambient light \n");
	//printf("his ratio is %f", data.ambient->light_ratio);
	//printf("and the rgb values are : %d %d %d \n", data.ambient->r, data.ambient->g, data.ambient->b);
	free_data(&data);
	return (0);
}
*/
