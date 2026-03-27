# include "minirt.h"

int	close_mlx(t_data *data)
{
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit(EXIT_SUCCESS);
}

void	my_mlx_put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (ft_printf("MLX INIT FAIL\n"), EXIT_FAILURE);
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT,
			"Welcome to a Magic World");
	if (!data->win)
		return (ft_printf("NEW WIN FAIL\n"), EXIT_FAILURE);
	data->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img)
		return (ft_printf("NEW IMG FAIL\n"), EXIT_FAILURE);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	if (!data->addr)
		return (ft_printf("GET ADDR FAIL\n"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	key_event(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		close_mlx(data);
	return (0);
}

void	setup_hooks(t_data *data)
{
	mlx_hook(data->win, 17, 0, close_mlx, data);
	mlx_key_hook(data->win, key_event, data);
}
