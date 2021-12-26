/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                 		:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclassie <kclassie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 19:45:24 by kclassie          #+#    #+#             */
/*   Updated: 2021/12/25 19:46:21 by kclassie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	arrow_keys(int keycode, t_params *params)
{
	t_complex	delta;

	delta.re = (params->max.re - params->min.re) / 100;
	delta.im = (params->max.im - params->min.im) / 100;
	if (keycode == ARROW_DOWN)
	{
		params->min.im += delta.im;
		params->max.im += delta.im;
	}
	else if (keycode == ARROW_UP)
	{
		params->min.im -= delta.im;
		params->max.im -= delta.im;
	}
	else if (keycode == ARROW_RIGHT)
	{
		params->min.re -= delta.re;
		params->max.re -= delta.re;
	}
	else if (keycode == ARROW_LEFT)
	{
		params->min.re += delta.re;
		params->max.re += delta.re;
	}
}

int	press_key(int keycode, t_params *params)
{
	if (keycode == ARROW_DOWN || keycode == ARROW_UP
		|| keycode == ARROW_RIGHT || keycode == ARROW_LEFT)
		arrow_keys(keycode, params);
	else if (keycode == MAIN_PAD_C)
		params->color_shift++;
	else if (keycode == MAIN_PAD_ESC)
		end_program(params);
	return (1);
}
