#include <stdio.h>
#include "fract_ol.h"

struct s_complex init_complex(double re, double im)
{
	struct s_complex complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

int set_color(int iter)
{
	double	red;
	double	green;
	double	blue;
	int 	color;

	red = sin(0.0001 * (double)iter);
	green = sin(0.0001 * (double)iter + 3) * 127 + 128;
	blue = sin(0.1 * (double)iter + 3) * 127 + 128;
	color = ((int)(255.999 * red) << 16) + ((int)(255.999 * green) << 8) + ((int)(255.999 * blue));
	return (color);
}

int event_handling(t_params *params, t_data *img_data)
{
	mlx_mouse_hook(s->win, mouse_reaction_click, s);
    mlx_key_hook(s->win, key_reaction, s);
    mlx_hook(s->win, 17, (1L << 17), red_cross, s);
    mlx_hook(s->win, KEYPRESS, KEYPRESSMASK, ft_movement, s);
    mlx_hook(s->win, MOTIONNOTIFY, POINTERMOTIOMMASK, mouse_reaction, s);
}


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int calculate_pixel(t_params *params, t_data *img_data)
{
	t_complex	z;
	int			x;
	int			y;
	int 		iter;
	int			color;

	y = 0;
	while (y < HEIGHT)
	{
		params->c_im = params->max_im - y * params->factor_im;
		x = 0;
		while (x < WIDTH)
		{
			params->c_re = params->min_re + x * params->factor_re;
			z = init_complex(params->c_re,params->c_im);
			iter = 0;
			while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
				   && iter < params->max_iter)
			{
				z = init_complex(
						pow(z.re, 2.0) - pow(z.im, 2.0) + params->c_re,
						2.0 * z.re * z.im + params->c_im);
				iter++;
			}
			color = set_color(iter);
			printf ("color1 %d\n", color);
			printf ("color2 %d\n", mlx_get_color_value(img_data->mlx_ptr,
													   0x00000010));
			my_mlx_pixel_put(img_data, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(img_data->mlx_ptr, img_data->win_ptr, img_data->img_ptr, 10, 10);
	return (0);
}

void 	init_window(t_data *img_data) //в функцию можно передавать код фрактала, чтобы писать соответствующее имя
{
	int 			x;
	int 			y;

	x = 0;
	y = 0;
	img_data->mlx_ptr = mlx_init();
	if (img_data->mlx_ptr == NULL)
	{
		printf("Server connection error\n");
		exit(EXIT_FAILURE);
	}
	img_data->img_ptr = mlx_new_image(img_data->mlx_ptr, WIDTH, HEIGHT);
	img_data->win_ptr = mlx_new_window(img_data->mlx_ptr, WIDTH, HEIGHT, "Mandelbrot Explorer");
	if (img_data->win_ptr == NULL)
	{
		printf("Server connection error\n");
		exit(EXIT_FAILURE);
	}
	img_data->addr = mlx_get_data_addr(img_data->img_ptr,
									   &img_data->bits_per_pixel, &img_data->line_length,
									   &img_data->endian);
}

struct s_params init_params()
{
	struct s_params	params;

	params.min_re = -2.0;
	params.max_re = 2.0;
	params.min_im = -2.0;
	params.max_im = params.min_im + (params.max_re - params.min_re) * HEIGHT / WIDTH;
	params.factor_re = (params.max_re - params.min_re) / (WIDTH - 1);
	params.factor_im = (params.max_im - params.min_im) / (HEIGHT - 1);
	params.max_iter = 100;

	return (params);
}

int do_mandelbrot()
{
	t_params	params;
	t_data 		img_data;

	img_data.endian = 1;
	params = init_params();
	init_window(&img_data);
	calculate_pixel(&params, &img_data);
	event_handling(&params, &img_data);
	mlx_loop(img_data.mlx_ptr);
	exit(EXIT_SUCCESS);
}

int do_julia()
{
	return (0);
}

void input_err()
{
	printf("usage: fractol [fractal]\nfractals:\n✅ Mandelbrot\n✅ Julia\n");
	exit(EXIT_FAILURE);
}

int	main(int argc, char  **argv)
{
	if (argc == 2)
	{
		if (ft_strncmp(argv[1], "Mandelbrot", 10) == 0)
			do_mandelbrot();
		else if (ft_strncmp(argv[1], "Julia", 5) == 0)
			printf("J\n");
//		do_julia();
		else
			input_err();
	}
	else
		input_err();
}


