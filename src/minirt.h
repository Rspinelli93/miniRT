#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <math.h>
# include "../minilibx_linux/mlx.h"
# include "../libftprintf/libftprintf.h"

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define KEY_ESC 65307

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	memset_t_data(t_data *data);
int	validate_args(int argc, char *argv[]);

int	close_mlx(t_data *data);
void	my_mlx_put_pixel(t_data *data, int x, int y, int color);
int	init_mlx(t_data *data);
void	setup_hooks(t_data *data);
int	put_blue_screen(t_data *data);

#endif
