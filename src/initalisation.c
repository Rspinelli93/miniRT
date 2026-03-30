# include "../minirt.h"

void	memset_t_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->img = NULL;
	data->addr = NULL;
	data->bits_per_pixel = 0;
	data->line_length = 0;
	data->endian = 0;
	data->ambient = NULL;
	data->camera = NULL;
	data->light = NULL;
	data->sphere = NULL;
	data->plane = NULL;
	data->cylinder = NULL;
}

int	validate_args(int argc, char *argv[])
{
	if (argc && argv[0])
		return (EXIT_SUCCESS);

	return (EXIT_FAILURE);
}
