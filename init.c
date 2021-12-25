#include "fractol.h"

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

void	reset_params(t_params *params)
{
	params->canva.length = WIN_LENGTH;
	params->canva.width = WIN_WIDTH;
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
