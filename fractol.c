#include "fractol.h"

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

void	reset_params(t_params *params)
{
	params->image.length = WIN_LENGTH;
	params->image.width = WIN_WIDTH;
	params->max_iteration = 100;
	params->change_julia_k = 0;
	if (params->argc == 4)
	{
		params->julia_k.re = ft_double(params->argv[2]);
		params->julia_k.im = ft_double(params->argv[3]);
	}
	else
	{
		params->julia_k.re = -0.4;
		params->julia_k.im = 0.6;
	}
	params->min.im = -2;
	params->min.re = -2;
	params->max.im = 2;
	params->max.re = 2;
	params->color_shift = 0;
}

static int	(*get_formula(char *name)) (int x, int y, t_params *params)
{
	size_t				i;
	int					(*formula)(int x, int y, t_params *vars);
	static t_formula	formulas[] = {
			{"Mandelbrot", &iterate_mandelbrot},
			{"Julia", &iterate_julia},
			{"Burning_Ship", &iterate_burning_ship},
	};

	i = 0;
	formula = NULL;
	while (i < (sizeof(formulas) / sizeof(t_formula)))
	{
		if (!ft_strncmp(name, formulas[i].name, ft_strlen(formulas[i].name)))
			formula = formulas[i].formula;
		i++;
	}
	return (formula);
}


int	init_params(t_params *params, char **argv)
{
	params->argv = argv;
	params->mlx_data.win = NULL;
	params->mlx_data.img = NULL;
	params->mlx_data.addr = NULL;
	params->press_mouse_button = 0;
	params->formula = get_formula(argv[1]);
	if (params->formula == NULL)
		return (0);
	if (params->argc == 4)
	{
		params->julia_k.re = ft_double(params->argv[2]);
		params->julia_k.im = ft_double(params->argv[3]);
		if (params->julia_k.im > 1.0 || params->julia_k.im < -1.0
			|| params->julia_k.re > 1.0 || params->julia_k.re < -1.0)
			return (0);
	}
	reset_params(params);
	params->mlx_data.mlx = mlx_init();
	return (1);
}

void	init_image(t_params *params)
{
	params->mlx_data.img = mlx_new_image(params->mlx_data.mlx, params->image.length,
										 params->image.width);
	params->mlx_data.addr = mlx_get_data_addr(params->mlx_data.img,
										   &params->mlx_data.bits_per_pixel, &params->mlx_data.line_length,
										   &params->mlx_data.endian);
	params->mlx_data.win = mlx_new_window(params->mlx_data.mlx, params->image.length,
										  params->image.width, params->argv[1]);
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
