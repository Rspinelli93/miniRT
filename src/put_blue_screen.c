# include "minirt.h"

int	put_blue_screen(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			my_mlx_put_pixel(data, x, y, 0x000000FF);
			x++;
		}
		y++;
	}
	return (EXIT_SUCCESS);
}
