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

t_color	fract_get_color(int iter, t_params *params) // TODO вот здесь надо понять, как это работает
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
