#include 	"fract_ol.h"

#define		X_EVENT_KEY_PRESS		2
#define		X_EVENT_KEY_EXIT		17
#define		X_EVENT_MOUSE_PRESS		4
#define		X_EVENT_MOUSE_MOTION	6
#define		WIN_WIDTH				800
#define		WIN_HEIGHT				600
#define		KEY_ESC					53
#define		ITER_MAX				100

typedef	struct	s_img{
	void		*img_ptr;
	char		*data;
	int			size_l;
	int			bpp;
	int			endian;
	int 		fractal_id;
}				t_img;

typedef	struct	s_mlx{
	void		*mlx_ptr;
	void		*win;
	t_img		img;
}				t_mlx;

//int		mouse_event(int button, int x, int y, t_mlx *mlx)
//{
//	if (button == SCROLL_UP)
//	{
//		mlx->zoom.max_width -= ZOOM * ((mlx->zoom.width - x) / mlx->zoom.width);
//		mlx->zoom.min_width += ZOOM * (x / mlx->zoom.width);
//		mlx->zoom.max_height -= ZOOM * ((mlx->zoom.height - y) / mlx->zoom.height);
//		mlx->zoom.min_height += ZOOM * (y / mlx->zoom.width);
//	}
//	else if (button == SCROLL_DOWN)
//	{
//		mlx->zoom.max_width += ZOOM * ((mlx->zoom.width - x) / mlx->zoom.width);
//		mlx->zoom.min_width -= ZOOM * (x / mlx->zoom.width);
//		mlx->zoom.max_height += ZOOM * ((mlx->zoom.height - y) / mlx->zoom.height);
//		mlx->zoom.min_height -= ZOOM * (y / mlx->zoom.height);
//	}
//	else
//		return (0);
//	mlx->zoom.width = mlx->zoom.max_width - mlx->zoom.min_width;
//	mlx->zoom.height = mlx->zoom.max_height - mlx->zoom.min_height;
//	return (0);
//}


int		mandelbrot(int count_w, int count_h, int iter)
{
	double c_re;
	double c_im;
	double x;
	double x_new;
	double y;

	c_re = ((count_w - WIN_WIDTH / 2) * 3.0 / WIN_WIDTH) - 0.5;
	c_im = ((WIN_HEIGHT / 2) - count_h) * 2.0 / WIN_HEIGHT;
	x = 0;
	y = 0;
	while ((pow(x, 2.0) + pow(y, 2.0) < 4) && (iter < ITER_MAX))
	{
		x_new = pow(x, 2.0) - pow(y, 2.0) + c_re;
		y = 2 * x * y + c_im;
		x = x_new;
		iter++;
	}
	return (iter);
}

int		color_set(int iter)
{
	double	r;
	double	g;
	double	b;
	int		color;

	r = sin(0.3 * (double)iter);
	g = sin(0.3 * (double)iter + 3) * 127 + 128;
	b = sin(0.3 * (double)iter + 3) * 127 + 128;
	color = ((int)(255.999 * r) << 16) + ((int)(255.999 * g) << 8) + ((int)(255.999 * b));
	return (color);
}

int		julia(int count_w, int count_h, int iter)
{
	double	c_re;
	double	c_im;
	double	x;
	double	x_new;
	double	y;

	c_re = -0.75;
	c_im = 0;
	x = ((count_w - WIN_WIDTH / 2) * 4.0 / WIN_WIDTH);
	y = ((WIN_HEIGHT / 2) - count_h) * 4.0 / WIN_HEIGHT;
	while ((pow(x, 2.0) + pow(y, 2.0) < 4) && (iter < ITER_MAX))
	{
		x_new = pow(x, 2.0) - pow(y, 2.0) + c_re;
		y = 2 * x * y + c_im;
		x = x_new;
		iter++;
	}
	return (iter);
}

int		window_init(t_mlx *mlx)
{
	if (!(mlx->mlx_ptr = mlx_init()))
		return (0);
	if (!(mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "A simple example")))
		return (0);
	if (!(mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT)))
		return (0);
	if (!(mlx->img.data = mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bpp, &mlx->img.size_l, &mlx->img.endian)))
		return (0);
	return (1);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->data + (x * img->bpp / 8) + (y * img->size_l);
	*(unsigned int *)dst = color;
}

void	put_pixel(t_mlx *mlx)
{
	int		iter;
	int		color;
	double	count_w;
	double	count_h;
	int		x_idx;
	int		y_idx;

	y_idx = -1;
	count_h = mlx->zoom.min_height;
	while (++y_idx <= WIN_HEIGHT)
	{
		x_idx = -1;
		count_w = mlx->zoom.min_width;
		while (++x_idx <= WIN_WIDTH)
		{
			iter = mandelbrot(count_w, count_h, 0, mlx);
			if (iter < ITER_MAX)
			{
				color = color_set(iter);
				my_mlx_pixel_put(&mlx->img, x_idx, y_idx, color);
			}
			else
				my_mlx_pixel_put(&mlx->img, x_idx, y_idx, 0x00000000);
			count_w += mlx->zoom.width / WIN_WIDTH;
		}
		count_h += mlx->zoom.height / WIN_HEIGHT;
	}
}

int		key_press(int keycode)
{
	if (keycode == KEY_ESC)
		exit(0);
	else
		return (0);
	return(0);
}

int		close()
{
	exit(0);
}

void input_err()
{
	printf("usage: fractol [fractal]\nfractals:\n✅ Mandelbrot\n✅ Julia\n");
	exit(EXIT_FAILURE);
}

int		do_fractal(int fractal_id)
{
	t_mlx	mlx;

	if (!window_init(&mlx))
		return (0);
	mlx.img.fractal_id = fractal_id;
	put_pixel(mlx.img);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, mlx.img.img_ptr, 0, 0);
//	mlx_hook(mlx.win, X_EVENT_KEY_PRESS, 0, key_press, 0);
//	mlx_hook(mlx.win, X_EVENT_KEY_EXIT, 0, close, 0);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}

int	main(int argc, char  **argv)
{
	(void)argc;
	if (argc == 2)
	{
		if (ft_strncmp(argv[1], "Mandelbrot", 10) == 0)
			do_fractal(1);
		else if (ft_strncmp(argv[1], "Julia", 5) == 0)
			do_fractal(2);
		else
			input_err();
	}
	else
		input_err();
}



