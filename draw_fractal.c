#include "fractol.h"

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_fractal(t_params *params)
{
	int				x;
	int				y;
	int				iter;
	t_color			color;

	x = 0;
	while (x < params->canva.width)
	{
		y = 0;
		while (y < params->canva.length)
		{
			iter = params->formula(x, y, params);
			color = fract_get_color(iter, params);
			my_mlx_pixel_put(&params->mlx_data, x, y, color.color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(params->mlx_data.mlx, params->mlx_data.win,
							params->mlx_data.img, 0, 0);
}
