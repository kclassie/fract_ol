/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press_button_control.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclassie <kclassie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 19:45:35 by kclassie          #+#    #+#             */
/*   Updated: 2021/12/25 19:46:09 by kclassie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

static void	zoom_screen(int keycode, int x, int y, t_params *params)
{
	t_complex	delta;
	double		interpolation;

	delta.re = (double)x / (params->image.width / (params->max.re - params->min.re)) + params->min.re;
	delta.im = (double)y / (params->image.length / (params->max.im - params->min.im)) * -1 + params->max.im;
	interpolation = 1;
	if (keycode == MOUSE_SCROLL_DOWN)
		interpolation = 1.05;
	else if (keycode == MOUSE_SCROLL_UP)
		interpolation = 0.95;
	params->min.re = interpolate(delta.re, params->min.re, interpolation);
	params->min.im = interpolate(delta.im, params->min.im, interpolation);
	params->max.re = interpolate(delta.re, params->max.re, interpolation);
	params->max.im = interpolate(delta.im, params->max.im, interpolation);
}

void	move_screen(int x, int y, t_params *params)
{
	t_complex	delta;
	static int	x1;
	static int	y1;
	static int	first_time = 1;

	if (!params->press_mouse_button)
	{
		first_time = 1;
		return ;
	}
	if (first_time)
	{
		x1 = x;
		y1 = y;
		first_time = 0;
		return ;
	}
	delta.re = (params->max.re - params->min.re) / params->image.width * (x1 - x);
	delta.im = (params->max.im - params->min.im) / params->image.length * (y - y1);
	params->min.im += delta.im;
	params->max.im += delta.im;
	params->min.re += delta.re;
	params->max.re += delta.re;
	x1 = x;
	y1 = y;
}

int	scroll_handler(int keycode, int x, int y, t_params *params)
{
	if (x < 0 || y < 0)
		return (0);
	if (keycode == MOUSE_SCROLL_DOWN || keycode == MOUSE_SCROLL_UP)
		zoom_screen(keycode, x, y, params);
	draw_fractal(params);
	return (0);
}

//int	release_mouse_button(int keycode, int x, int y, t_params *params)
//{
//	if (keycode == MOUSE_LEFT_BUTTON)
//	{
//		params->press_mouse_button = 0;
//		move_screen(x, y, params);
//	}
//	draw_fractal(params);
//	return (0);
//}
