/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melyaaco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 20:45:31 by melyaaco          #+#    #+#             */
/*   Updated: 2023/12/28 17:04:47 by melyaaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	zoomm(int button, int x, int y, t_args *args)
{
	double	a;
	double	b;

	a = x * (args->max_x - args->min_x) / 800 + args->min_x;
	b = y * (args->max_y - args->min_y) / 800 + args->min_y;
	apply_zoom(button, a, b, args);
	if (button == 4 || button == 5)
	{
		iterating(args);
		mlx_put_image_to_window(args->mlx, args->mlx_win, args->img->img, 1, 1);
	}
	printf("%d\n", button);
	return (0);
}

int	key(int button, t_args *args)
{
	if (button == 53)
		exit(1);
	/* mlx_destroy_window(vars.mlx, vars.mlx_win); free(vars.mlx);*/
	mouve(button, args);
	if (button == 124 || button == 123 || button == 126 || button == 125)
	{
		printf("%f %f %f %f\n", args->min_x, args->max_x, args->min_y, args->max_y);
		iterating(args);
		mlx_put_image_to_window(args->mlx, args->mlx_win,
			args->img->img, 1, 1);
	}
	return (0);
}

void	iterating(t_args *args)
{
	double	x;
	double	y;

	args->i = 0;
	while (args->i < 800)
	{
		args->j = 0;
		while (args->j < 800)
		{
			x = args->i * (args->max_x - args->min_x) / 800 + args->min_x;
			y = args->j * (args->max_y - args->min_y) / 800 + args->min_y;
			if (args->set == 2)
				plan_julia(x, y, args);
			else if (args->set == 1)
				plan(x, y, args);
			else
				ship (x, y, args);
			args->j++;
		}
		args->i++;
	}
}

int	main(int ac, char **av)
{
	t_args	data;
	t_data	img;

	if (!param(ac, av, &data))
		return (1);
	data.min_x = -2;
	data.max_x = 2;
	data.min_y = -2;
	data.max_y = 2;
	data.var = 1;
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 800, 800, "FRACTAL");
	img.img = mlx_new_image(data.mlx, 800, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	data.img = &img;
	iterating(&data);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img->img, 1, 1);
	mlx_key_hook(data.mlx_win, key, &data);
	mlx_mouse_hook(data.mlx_win, zoomm, &data);
	mlx_hook(data.mlx_win, 17, 0, close, NULL);
	mlx_loop(data.mlx);
	return (0);
}
