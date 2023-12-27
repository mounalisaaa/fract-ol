/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melyaaco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 20:59:40 by melyaaco          #+#    #+#             */
/*   Updated: 2023/12/27 20:59:57 by melyaaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	plan(double a, double b, t_args *args)
{
	double	z_im;
	double	z_r;
	int		k;
	double	temp;
	int		color;

	k = 0;
	z_im = b;
	z_r = a;
	while (k < 100)
	{
		temp = 2 * z_im * z_r + b;
		z_r = z_r * z_r - z_im * z_im + a;
		z_im = temp;
		if (z_r * z_r + z_im * z_im > 4)
		{
			color = get_color(k);
			return (my_pixel_put(args->img, args->i, args->j, color));
		}
		k++;
	}
	return (my_pixel_put(args->img, args->i, args->j, 0x00000000));
}

void	ship(double a, double b, t_args *args)
{
	double	z_im;
	double	z_r;
	int		k;
	double	temp;
	int		color;

	z_im = b;
	z_r = a;
	k = 0;
	while (k < 100)
	{
		temp = fabs(2 * z_im * z_r) + b;
		z_r = z_r * z_r - z_im * z_im + a;
		z_im = temp;
		if (z_r * z_r + z_im * z_im > 4)
		{
			color = get_color(k);
			return (my_pixel_put(args->img, args->i, args->j, color));
		}
		k++;
	}
	return (my_pixel_put(args->img, args->i, args->j, 0x00000000));
}

void	plan_julia(double a, double b, t_args *args)
{
	double	z_im;
	double	z_r;
	int		k;
	double	temp;
	int		color;

	z_im = b;
	z_r = a;
	k = 0;
	while (k < 100)
	{
		temp = (2 * z_im * z_r + args->b);
		z_r = (z_r * z_r - z_im * z_im + args->a);
		z_im = temp;
		if (z_r * z_r + z_im * z_im > 4)
		{
			color = get_color(k);
			return (my_pixel_put(args->img, args->i, args->j, color));
		}
		k++;
	}
	return (my_pixel_put(args->img, args->i, args->j, 0x00000000));
}
