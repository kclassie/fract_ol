/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_fractals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclassie <kclassie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 19:44:21 by kclassie          #+#    #+#             */
/*   Updated: 2021/12/25 19:44:36 by kclassie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iterate_mandelbrot(int x, int y, t_params *params)
{
	t_complex	base_point;
	t_complex	z;
	int			i;
	double		tmp;

	(void)params;
	base_point.re = params->min.re + x * ((params->max.re - params->min.re)
			/ (params->image.width));
	base_point.im = params->max.im - y * ((params->max.im - params->min.im)
			/ (params->image.length));
	z = base_point;
	i = 0;
	while (z.re * z.re + z.im * z.im < 4 && i < params->max_iteration)
	{
		tmp = z.re;
		z.re = z.re * z.re - z.im * z.im + base_point.re;
		z.im = 2 * z.im * tmp + base_point.im;
		i++;
	}
	return (i);
}

int	iterate_julia(int x, int y, t_params *params)
{
	t_complex	base_point;
	t_complex	z;
	int			i;
	double		tmp;

	(void)params;
	base_point = (t_complex){
		params->min.re + x * ((params->max.re - params->min.re)
			/ (params->image.width)),
		params->max.im - y * ((params->max.im - params->min.im)
			/ (params->image.length))};
	z = base_point;
	i = 0;
	while (z.re * z.re + z.im * z.im <= 4 && i < params->max_iteration)
	{
		tmp = z.re;
		z.re = z.re * z.re - z.im * z.im + params->julia_k.re;
		z.im = 2 * z.im * tmp + params->julia_k.im;
		i++;
	}
	return (i);
}

int	iterate_burning_ship(int x, int y, t_params *params)
{
	t_complex	base_point;
	t_complex	z;
	int			i;
	double		tmp;

	(void)params;
	base_point.re = params->min.re + x * ((params->max.re - params->min.re)
			/ (params->image.width));
	base_point.im = params->max.im - y * ((params->max.im - params->min.im)
			/ (params->image.length));
	z = base_point;
	i = 0;
	while (z.re * z.re + z.im * z.im < 4 && i < params->max_iteration)
	{
		tmp = z.re;
		z.re = z.re * z.re - z.im * z.im + base_point.re;
		z.im = -2 * fabs(z.im * tmp) + base_point.im;
		i++;
	}
	return (i);
}
