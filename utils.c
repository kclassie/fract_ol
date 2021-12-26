/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclassie <kclassie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 19:45:39 by kclassie          #+#    #+#             */
/*   Updated: 2021/12/25 19:45:45 by kclassie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
