#ifndef FRACTOL_H
#define FRACTOL_H
#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

}				t_data;

typedef struct s_args {
	void *mlx;
    void *mlx_win;
    double min_x;
    double max_x;
    double min_y;
    double max_y;
    t_data *img;
    int set;
    double a;
    double b;
    double var;
    int flag;

}	t_args;

typedef struct t_point{
	double x;
	double y;
}		pixel;

void iterating(t_args *data);
int get_color(int k);

//helpers.c
int	ft_strcmp(char *str1, char *str2);
void my_pixel_put(t_data *data, int x, int y, int color);
double ft_atof(char *str);
#endif
