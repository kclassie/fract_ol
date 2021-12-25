/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclassie <kclassie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 19:45:19 by kclassie          #+#    #+#             */
/*   Updated: 2021/12/25 19:46:26 by kclassie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>

# define WIN_HEIGHT 800
# define WIN_WIDTH 800
# define MOUSE_SCROLL_UP	4
# define MOUSE_SCROLL_DOWN	5
# define MOUSE_LEFT_BUTTON	1
# define ARROW_UP			126
# define ARROW_DOWN			125
# define ARROW_LEFT			123
# define ARROW_RIGHT		124
# define MAIN_PAD_ESC		53
# define MAIN_PAD_C			8
# define BUTTON_PRESS			04
# define BUTTON_PRESS_MASK		1L<<2
# define BUTTON_RELEASE			05
# define BUTTON_RELEASE_MASK	1L<<3
# define MOTION_NOTIFY			06
# define BUTTON1_MOTION_MASK	1L<<8
# define KEY_PRESS				02
# define KEY_PRESS_MASK			1L<<0
# define DESTROY_NOTIFY			17
# define STRUCTURE_NOTIFY_MASK 	1L<<17
# define POINTER_MOTION_MASK	1L<<6

typedef union u_color
{
	unsigned int	color;
	struct s_rgb
	{
		unsigned int	b : 8;
		unsigned int	g : 8;
		unsigned int	r : 8;
	}	t_rgb;
}	t_color;

typedef struct s_complex
{
	double			re;
	double			im;
}					t_complex;

typedef struct s_data
{
	void	*mlx;
	void	*img;
	void	*win;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_image
{
	int		length;
	int		width;
}	t_image;

typedef struct s_params
{
	int			argc;
	char		**argv;
	t_data		mlx_data;
	t_image		image;
	int			max_iteration;
	t_complex	min;
	t_complex	max;
	t_complex	julia_k;
	int			change_julia_k;
	int			press_mouse_button;
	int			(*formula)(int x, int y, struct s_params *params);
	int			color_shift;
}	t_params;

typedef struct s_formula
{
	char	*name;
	int		(*formula)(int x, int y, t_params *params);
}	t_formula;

double	ft_double(char *nbr);
void	output_usage(void);
t_color	new_color(int r, int g, int b);
t_color	fract_get_color(int iteration, t_params *params);
int		scroll_handler(int keycode, int x, int y, t_params *params);
int		release_mouse_button(int keycode, int x, int y, t_params *params);
int		pointer_handler(int x, int y, t_params *params);
int		motion_mouse(int x, int y, t_params *params);
void	move_screen(int x, int y, t_params *params);
int		press_key(int keycode, t_params *params);
void	reset_params(t_params *params);
int		init_params(t_params *params, char **argv);
int		end_program(t_params *params);
void	draw_fractal(t_params *params);
int		iterate_mandelbrot(int x, int y, t_params *params);
int		iterate_julia(int x, int y, t_params *params);
int		iterate_burning_ship(int x, int y, t_params *params);

#endif
