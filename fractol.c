#include "fractol.h"

void	output_usage(void)
{
	printf("Usage: ./fractol <name> [(float)k1 (float)k2]\n");
	printf("k1, k2 - the parameters (from -1 to 1) for Julia\n(default [-0.4, 0.6])\n\n");
	printf("List of available fractals:\n * Mandelbrot\n * Julia\n * Burning_Ship");
}

int	check_double(char *str)
{
	int	i;

	i = 0;
	if (*str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		str++;
		i++;
	}
	if (*str == '.' && i <= 5)
	{
		str++;
		while (ft_isdigit(*str))
		{
			str++;
			i++;
		}
		if (*str == '\0' && i > 0 && i <= 10)
			return (1);
	}
	else if (*str == '\0' && i > 0)
		return (1);
	return (0);
}

void	init_image(t_params *params)
{
	params->mlx_data.img = mlx_new_image(params->mlx_data.mlx, params->canva.length,
										 params->canva.width);
	params->mlx_data.addr = mlx_get_data_addr(params->mlx_data.img,
											  &params->mlx_data.bits_per_pixel, &params->mlx_data.line_length,
											  &params->mlx_data.endian);
	params->mlx_data.win = mlx_new_window(params->mlx_data.mlx, params->canva.length,
										  params->canva.width, params->argv[1]);
//	mlx_put_image_to_window(params->mlx_data.mlx, params->mlx_data.win,
//							params->mlx_data.img, 0, 0);
	mlx_hook(params->mlx_data.win, ButtonPress, ButtonPressMask, press_mouse_button, params);
	mlx_hook(params->mlx_data.win, ButtonRelease, ButtonReleaseMask, release_mouse_button, params);
	mlx_hook(params->mlx_data.win, MotionNotify, Button1MotionMask, motion_mouse, params);
	mlx_hook(params->mlx_data.win, KeyPress, KeyPressMask, press_key, params);
	mlx_hook(params->mlx_data.win, DestroyNotify, StructureNotifyMask, end_program, params);
	draw_fractal(params);
	mlx_loop(params->mlx_data.mlx);
}

int	main(int argc, char **argv)
{
	t_params	params;

	params.argc = argc;
	if (argc != 2 && argc != 4)
	{
		output_usage();
		exit(EXIT_FAILURE);
	}
	if (argc == 4)
	{
		if (!check_double(argv[2]) || !check_double(argv[3]))
		{
			output_usage();
			exit(EXIT_FAILURE);
		}
	}
	if (!init_params(&params, argv))
	{
		output_usage();
		end_program(&params);
	}
	init_image(&params);
}
