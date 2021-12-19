#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "libft/libft.h"
# include "mlx.h"

# define MIN_X -2
# define MAX_X  2
# define MIN_Y -2
# define HEIGHT 800
# define WIDTH 1200

typedef struct s_params
{
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	double	factor_re;
	double	factor_im;
	double	c_re;
	double	c_im;
	int		max_iter;

}		t_params;

typedef struct	s_complex
{
	double re;
	double im;
}		t_complex;

typedef struct	s_data {
	void 	*mlx_ptr;
	void 	*win_ptr;
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

#endif
