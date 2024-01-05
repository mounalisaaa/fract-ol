/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melyaaco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:18:53 by melyaaco          #+#    #+#             */
/*   Updated: 2024/01/05 15:25:19 by melyaaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	check_flag(int *flag)
{
	if (!*flag)
	{
		*flag = 1;
		return (0);
	}
	return (1);
}

int	dsign(char *str, int *i, int *flag)
{
	int	sign;

	while (is_space(str[*i]))
		*i += 1;
	*flag = str[*i];
	if (!(check_flag(flag)))
		return (0);
	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign *= -1;
		*i += 1;
	}
	*flag = str[*i];
	printf("%d\n", *flag);
	if (!(check_flag(flag)))
		return (0);
	return (sign);
}

double	ft_atof(char *str, int *flag)
{
	int		i;
	double	res;
	int		sign;
	double	j;

	i = 0;
	res = 0;
	sign = dsign(str, &i, flag);
	if (!sign)
		return (0);
	while ((str[i] >= '0' && str[i] <= '9'))
		res = (res * 10) + str[i++] - '0';
	if (str[i] == '.')
		i++;
	j = 10;
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		res = res + ((str[i++] - '0') / j);
		j *= 10;
	}
	*flag = (str[i]);
	return (res * sign);
}

void	merror(void)
{
	ft_putstr("Error");
	exit(1);
}
