/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclassie <kclassie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 13:01:29 by kclassie          #+#    #+#             */
/*   Updated: 2021/12/26 13:01:34 by kclassie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	output_usage(void)
{
	printf("USAGE:\n______________________________________________\n");
	printf("To run the program enter: ./fractol <name of fractal>");
	printf("[(float)k1 (float)k2]\n");
	printf("where k1, k2 - the parameters for Julia fractal (from -1 to 1) \n");
	printf("default values: [-0.4, 0.6]).\n");
	printf("______________________________________________________\n");
	printf("List of available fractals:\n");
	printf("* Mandelbrot\n* Julia\n* Burning_Ship.\n");
	printf("______________________________________________________\n");
	printf("- Press ARROWS to move the image.\n");
	printf("- Scroll UP and DOWN to zoom the fractal.\n");
	printf("- Press C-key to change the palette.\n");
	printf("- For exit press ESC or close the window.\n");
}

int	end_program(t_params *params)
{
	if (params->mlx_data.img)
		mlx_destroy_image(params->mlx_data.mlx, params->mlx_data.img);
	if (params->mlx_data.win)
		mlx_destroy_window(params->mlx_data.mlx, params->mlx_data.win);
	exit (EXIT_SUCCESS);
}
