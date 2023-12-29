/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melyaaco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:18:53 by melyaaco          #+#    #+#             */
/*   Updated: 2023/12/29 14:26:00 by melyaaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

double	ft_atof(char *str)
{
	int		i;
	double	res;
	int		sign;
	double	j;

	i = 0;
	res = 0;
	while (is_space(str[i]))
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9'))
		res = (res * 10) + str[i++] - '0';
	j = 10;
	while (str[i] == '.' || (str[i] >= '0' && str[i] <= '9'))
	{
		if (str[i] == '.')
			i++;
		res = res + ((str[i++] - '0') / j);
		j *= 10;
	}
	return (res * sign);
}
