#include "fractol.h"

static void	arrow_keys(int keycode, t_params *params)
{
	t_complex	delta;

	delta = (t_complex){(params->max.re - params->min.re) / 100,
						(params->max.im - params->min.im) / 100};
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

static void	change_fractal(int keycode, t_params *params)
{
	if (keycode == MAIN_PAD_1)
		params->formula = &iterate_mandelbrot;
	else if (keycode == MAIN_PAD_2)
		params->formula = &iterate_julia;
	else if (keycode == MAIN_PAD_4)
		params->formula = &iterate_burning_ship;
}

int	press_key(int keycode, t_params *params)
{
	if (keycode == MAIN_PAD_PLUS || keycode == NUM_PAD_PLUS)
		params->max_iteration++;
	else if (keycode == MAIN_PAD_MINUS || keycode == NUM_PAD_MINUS)
		params->max_iteration--;
	else if (keycode == ARROW_DOWN || keycode == ARROW_UP
		|| keycode == ARROW_RIGHT || keycode == ARROW_LEFT)
		arrow_keys(keycode, params);
	else if (keycode == MAIN_PAD_R)
		reset_params(params);
	else if (keycode == MAIN_PAD_C)
		params->color_shift++;
	else if (keycode == MAIN_PAD_SPACE)
		params->change_julia_k = !params->change_julia_k;
	else if (keycode == MAIN_PAD_ESC)
		end_program(params);
	else if (keycode == MAIN_PAD_1 || keycode == MAIN_PAD_2
		|| keycode == MAIN_PAD_3 || keycode == MAIN_PAD_4
		|| keycode == MAIN_PAD_5 || keycode == MAIN_PAD_6
		|| keycode == MAIN_PAD_7 || keycode == MAIN_PAD_8
		|| keycode == MAIN_PAD_9)
		change_fractal(keycode, params);
	draw_fractal(params);
	return (1);
}
