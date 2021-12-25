/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_motion_control.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclassie <kclassie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 19:45:31 by kclassie          #+#    #+#             */
/*   Updated: 2021/12/25 19:46:16 by kclassie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	pointer_handler(int x, int y, t_params *params)
{
	if (params->formula == &iterate_julia
		&& x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		params->julia_k.re = ((double)x - (double)params->image.width / 2)
								 / ((double)params->image.width / 2);
		params->julia_k.im = ((double)y - (double)params->image.length / 2)
								 / ((double)params->image.length / 2);
		draw_fractal(params);
	}
	return (0);
}

//int	motion_mouse(int x, int y, t_params *params)
//{
//	if (params->press_mouse_button && x > 0 && y > 0 && x < params->image.width
//		&& y < params->image.length)
//	{
//		move_screen(x, y, params);
//	}
//	else if (params->change_julia_k && (x > 0 && y > 0 && x < params->image.width
//			&& y < params->image.length))
//	{
//		params->julia_k.re = ((double)x - (double)params->image.width / 2)
//			/ ((double)params->image.width / 2);
//		params->julia_k.im = ((double)y - (double)params->image.length / 2)
//			/ ((double)params->image.length / 2);
//		draw_fractal(params);
//	}
//	draw_fractal(params);
//	return (0);
//}


