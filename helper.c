/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melyaaco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:43:42 by melyaaco          #+#    #+#             */
/*   Updated: 2023/12/28 16:25:16 by melyaaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	get_color(int it)
{
	double	x;
	int		red;
	int		blue;
	int		green;

	if (it == 100)
		return (0);
	else
	{
		x = (double)it / 100;
		red = (int)(12* (1 - x) * x * x * x * 255);
		green = (int)(8 * (1 - x) * (1 - x) * x * x * 255);
		blue = (int)(10 * (1 - x) * (1 - x) * (1 - x) * x * 255);
	}
	return ((red << 16) + (green << 8) + blue);
}

void	invalid(void)
{
	printf("Invalid parameter\n");
	printf("Usage: ./fractol [valid_parameter]\n");
	printf("Valid parameter:\n");
	printf("  Mandelbrot	Display the Mandelbrot fractal\n");
	printf("  Ship		Display the Burning Ship fractal\n");
	exit(1);
}

void	invalid_julia(void)
{
	printf("Invalid parameter\n");
	printf("Usage: ./fractol Julia {real} {imaginary} \n");
	printf("Create different Julia sets by specifying");
	printf("the real and imaginary numbers.\n");
	printf("Example:\n");
	printf("  ./fractol Julia -0.835 -0.2321\n");
	exit(1);
}

int	param(int ac, char **av, t_args *data)
{
	if (ac == 2 || ac == 1)
	{
		if (ac == 2 && ft_strcmp("Mandelbrot", av[1]) == 0)
			data->set = 1;
		else if (ac == 2 && ft_strcmp("Ship", av[1]) == 0)
			data->set = 3;
		else
			invalid();
	}
	else if (ac >= 4 || ac == 3 )
	{
		if (ac == 4 && ft_strcmp("Julia", av[1]) == 0)
		{
			data->set = 2;
			data->a = atof(av[2]);
			data->b = atof(av[3]);
		}
		else
			invalid_julia();
	}
	else
		return (0);
	return (1);
}
