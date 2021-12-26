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

# define WIN_HEIGHT				800
# define WIN_WIDTH 				800
# define MOUSE_SCROLL_UP		4
# define MOUSE_SCROLL_DOWN		5
# define ARROW_UP				126
# define ARROW_DOWN				125
# define ARROW_LEFT				123
# define ARROW_RIGHT			124
# define MAIN_PAD_ESC			53
# define MAIN_PAD_C				8
# define BUTTON_PRESS			04
# define MOTION_NOTIFY			06
# define KEY_PRESS				02
# define DESTROY_NOTIFY			17

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
	int			(*formula)(int x, int y, struct s_params *params);
	int			color_shift;
}	t_params;

typedef struct s_formula
{
	char	*name;
	int		(*formula)(int x, int y, t_params *params);
}	t_formula;

double	ft_double(char *nbr);
int		check_double(char *str);
void	output_usage(void);
t_color	new_color(int r, int g, int b);
t_color	init_color(int iteration, t_params *params);
int		scroll_handler(int keycode, int x, int y, t_params *params);
int		pointer_handler(int x, int y, t_params *params);
int		press_key(int keycode, t_params *params);
void	reset_params(t_params *params);
int		init_params(t_params *params, char **argv);
int		end_program(t_params *params);
int		draw_fractal(t_params *params);
int		do_mandelbrot(int x, int y, t_params *params);
int		do_julia(int x, int y, t_params *params);
int		do_burning_ship(int x, int y, t_params *params);

#endif
