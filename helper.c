/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melyaaco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:43:42 by melyaaco          #+#    #+#             */
/*   Updated: 2023/12/29 14:18:40 by melyaaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

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
		red = (int)(9 * (1 - x) * x * x * x * 255);
		green = (int)(15 * (1 - x) * (1 - x) * x * x * 255);
		blue = (int)(8.5 * (1 - x) * (1 - x) * (1 - x) * x * 255);
	}
	return ((red << 16) + (green << 8) + blue);
}

void	invalid(void)
{
	ft_putstr("Invalid parameter\n");
	ft_putstr("Usage: ./fractol [valid_parameter]\n");
	ft_putstr("Valid parameter:\n");
	ft_putstr("  Mandelbrot	Display the Mandelbrot fractal\n");
	ft_putstr("  Ship		Display the Burning Ship fractal\n");
	invalid_julia(void);
	exit(1);
}

void	invalid_julia(void)
{
	ft_putstr("Invalid parameter\n");
	ft_putstr("Usage: ./fractol Julia {real} {imaginary} \n");
	ft_putstr("Create different Julia sets by specifying");
	ft_putstr("the real and imaginary numbers.\n");
	ft_putstr("Example:\n");
	ft_putstr("  ./fractol Julia 0 0.8\n");
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
	else if (ac >= 4 || ac == 3)
	{
		if (ac == 4 && ft_strcmp("Julia", av[1]) == 0)
		{
			data->set = 2;
			data->a = ft_atof(av[2]);
			data->b = ft_atof(av[3]);
		}
		else
			invalid_julia();
	}
	else
		return (0);
	return (1);
}
