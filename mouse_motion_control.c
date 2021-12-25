#include "fractol.h"

int	motion_mouse(int x, int y, t_params *params)
{
	if (params->press_mouse_button && x > 0 && y > 0 && x < params->image.width
		&& y < params->image.length)
	{
		move_screen(x, y, params);
	}
	else if (params->change_julia_k && (x > 0 && y > 0 && x < params->image.width
			&& y < params->image.length))
	{
		params->julia_k.re = ((double)x - (double)params->image.width / 2)
			/ ((double)params->image.width / 2);
		params->julia_k.im = ((double)y - (double)params->image.length / 2)
			/ ((double)params->image.length / 2);
		draw_fractal(params);
	}
	draw_fractal(params);
	return (0);
}
