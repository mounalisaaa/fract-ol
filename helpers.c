/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melyaaco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:56:47 by melyaaco          #+#    #+#             */
/*   Updated: 2023/12/27 21:03:55 by melyaaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *str1, char *str2)
{
	int			i;

	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	close(void *data)
{
	(void)data;
	exit(1);
	printf("closed");
	return (0);
}

void	mouve(int button, t_args *args)
{
	double	move;

	move = args->var;
	printf("move: %f\n", move);
	if (button == 124)
	{
		args->min_x += move;
		args->max_x += move;
	}
	if (button == 123)
	{
		args->min_x -= move;
		args->max_x -= move;
	}
	if (button == 126)
	{
		args->min_y -= move;
		args->max_y -= move;
	}
	if (button == 125)
	{
		args->min_y += move;
		args->max_y += move;
	}
}

void	apply_zoom(int button, double a, double b, t_args *args)
{
	if (button == 5 && args->flag < 150)
	{
		// zoom in
		args->min_x = a + (args->min_x - a) / 1.25;
		args->min_y = b + (args->min_y - b) / 1.25;
		args->max_x = a + (args->max_x - a) / 1.25;
		args->max_y = b + (args->max_y - b) / 1.25;
		args->flag++;
		args->var /= 1.25;
	}
	if (button == 4)
	{
		args->min_x = a + (args->min_x - a) * 1.25;
		args->min_y = b + (args->min_y - b) * 1.25;
		args->max_x = a + (args->max_x - a) * 1.25;
		args->max_y = b + (args->max_y - b) * 1.25;
		args->flag--;
		args->var *= 1.25;
	}
}
