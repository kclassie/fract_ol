#include "fractol.h"

int	motion_mouse(int x, int y, t_params *params)
{
	if (params->press_mouse_button && x > 0 && y > 0 && x < params->canva.width
		&& y < params->canva.length)
	{
		move_screen(x, y, params);
	}
	else if (params->change_julia_k && (x > 0 && y > 0 && x < params->canva.width
			&& y < params->canva.length))
	{
		params->julia_k.re = ((double)x - (double)params->canva.width / 2)
			/ ((double)params->canva.width / 2);
		params->julia_k.im = ((double)y - (double)params->canva.length / 2)
			/ ((double)params->canva.length / 2);
		draw_fractal(params);
	}
	draw_fractal(params);
	return (0);
}
