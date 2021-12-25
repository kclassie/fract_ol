#include "fractol.h"

static double	get_result_part1(char **nbr)
{
	double	result_part1;

	result_part1 = 0;
	while (ft_isdigit(**nbr))
	{
		result_part1 = result_part1 * 10 + (**nbr - '0');
		(*nbr)++;
	}
	return (result_part1);
}

static double	get_result_part2(char **nbr)
{
	double	result_part2;

	result_part2 = 0;
	while (ft_isdigit(**nbr))
		(*nbr)++;
	(*nbr)--;
	while (ft_isdigit(**nbr))
	{
		result_part2 = (result_part2 + (**nbr - '0')) / 10;
		(*nbr)--;
	}
	return (result_part2);
}

double	ft_double(char *nbr)
{
	double	result_part1;
	double	result_part2;
	int		minus;
	double	result;

	if (nbr == NULL)
		return (0);
	minus = 0;
	if (*nbr == '-')
	{
		minus = 1;
		nbr++;
	}
	result_part1 = get_result_part1(&nbr);
	result_part2 = 0;
	if (*nbr == '.')
	{
		nbr++;
		result_part2 = get_result_part2(&nbr);
	}
	result = result_part1 + result_part2;
	if (minus)
		result = -result;
	return (result);
}

int	end_program(t_params *params)
{
	if (params->mlx_data.img)
		mlx_destroy_image(params->mlx_data.mlx, params->mlx_data.img);
	if (params->mlx_data.win)
		mlx_destroy_window(params->mlx_data.mlx, params->mlx_data.win);
	exit (EXIT_SUCCESS);
}
