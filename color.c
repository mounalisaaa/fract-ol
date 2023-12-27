/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melyaaco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:43:42 by melyaaco          #+#    #+#             */
/*   Updated: 2023/12/27 19:48:48 by melyaaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	get_color(int it)
{
	// int	colors[6];
	// int	index;

	// colors[0] = 0x0b232a;
	// colors[1] = 0x0f3642;
	// colors[2] = 0x106575;
	// colors[3] = 0x4babb1;
	// colors[4] = 0xa2d5dd;
	// colors[5] = 0;
	// /*Determine the color based on the iteration counti*/
	// index = it % (sizeof(colors) / sizeof(colors[0]));
	// return (colors[index]);

	double        x;
    int            red;
    int            blue;
    int            green;

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
