/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melyaaco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:55:28 by melyaaco          #+#    #+#             */
/*   Updated: 2024/01/05 15:26:11 by melyaaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

}				t_data;

typedef struct s_args
{
	void	*mlx;
	void	*mlx_win;
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
	t_data	*img;
	int		set;
	double	a;
	double	b;
	double	var;
	int		flag;
	int		i;
	int		j;
}	t_args;

void	iterating(t_args *data);
int		get_color(int k);

//helpers.c
int		ft_strcmp(char *str1, char *str2);
void	my_pixel_put(t_data *data, int x, int y, int color);
double	ft_atof(char *str, int *flag);
int		ft_close(void *data);
void	apply_zoom(int button, double a, double b, t_args *args);
void	mouve(int button, t_args *args);
void	invalid(void);
void	invalid_julia(void);
void	param(int ac, char **av, t_args *data);
void	ft_putstr(char *str);
void	merror(void);

//set
void	plan(double a, double b, t_args *args);
void	ship(double a, double b, t_args *args);
void	plan_julia(double a, double b, t_args *args);
#endif
