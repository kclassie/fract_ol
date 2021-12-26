/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclassie <kclassie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 19:44:55 by kclassie          #+#    #+#             */
/*   Updated: 2021/12/25 19:44:57 by kclassie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	clamp(int data, int min, int max)
{
	if (data > max)
		return (max);
	if (data < min)
		return (min);
	return (data);
}

t_color	new_color(int r, int g, int b)
{
	t_color	color;

	color.t_rgb.r = clamp(r, 0, 255);
	color.t_rgb.g = clamp(g, 0, 255);
	color.t_rgb.b = clamp(b, 0, 255);
	return (color);
}

t_color	init_color(int iter, t_params *params)
{
	t_color	color;
	double	t;

	t = (double)iter / params->max_iteration;
	color = new_color(0, 0, 0);
	if (!(iter == 0 || (iter == params->max_iteration)))
	{
		if (params->color_shift % 3 == 1)
			color = new_color((int)(8.5 * pow((1 - t), 3) * t * 255),
					(int)(9 * (1 - t) * pow(t, 3) * 255),
					(int)(15 * pow((1 - t), 2) * pow(t, 2) * 255));
		else if (params->color_shift % 3 == 2)
			color = new_color((int)(15 * pow((1 - t), 2) * pow(t, 2) * 255),
					(int)(8.5 * pow((1 - t), 3) * t * 255),
					(int)(9 * (1 - t) * pow(t, 3) * 255));
		else
			color = new_color((int)(9 * (1 - t) * pow(t, 3) * 255),
					(int)(15 * pow((1 - t), 2) * pow(t, 2) * 255),
					(int)(8.5 * pow((1 - t), 3) * t * 255));
	}
	return (color);
}

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	draw_fractal(t_params *params)
{
	int				x;
	int				y;
	int				iter;
	t_color			color;

	x = 0;
	while (x < params->image.width)
	{
		y = 0;
		while (y < params->image.length)
		{
			iter = params->formula(x, y, params);
			color = init_color(iter, params);
			my_mlx_pixel_put(&params->mlx_data, x, y, color.color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(params->mlx_data.mlx, params->mlx_data.win,
		params->mlx_data.img, 0, 0);
	return (0);
}
