#include "fractol.h"


void plan (double a, double b, t_args *args, int i, int j)
{
	double z_im = b;
	double z_r = a;
	int k = 0;
	double temp;
	int color;
	for (; k < 100; k++)
	{
		temp = 2 * z_im * z_r + b;
		z_r = z_r * z_r  - z_im * z_im + a;
		z_im = temp;
		if (z_r * z_r + z_im * z_im > 4)
		{
			color = get_color(k);
			return(my_pixel_put(args->img, i, j, color));
		}
	}
	return (my_pixel_put(args->img, i, j, 0x00000000));
}
void ship(double a, double b, t_args *args, int i, int j)
{
	double z_im = b;
	double z_r = a;
	int k = 0;
	double temp;
	int color;
	for (; k < 100; k++)
	{
		temp = fabs(2 * z_im * z_r) + b;
		z_r = z_r * z_r  - z_im * z_im + a;
		z_im = temp;
		if (z_r * z_r + z_im * z_im > 4)
		{
			color = get_color(k);
			return(my_pixel_put(args->img, i, j, color));
		}
	}
	return (my_pixel_put(args->img, i, j, 0x00000000));
}
void plan_julia (double a, double b, t_args *args, int i, int j)
{
	double z_im = b;
	double z_r = a;
	int k = 0;
	double temp;
	int color;
	for (; k < 100; k++)
	{
		temp = (2 * z_im * z_r + args->b);
		z_r = (z_r * z_r  - z_im * z_im + args->a);
		z_im = temp;
		if (z_r * z_r + z_im * z_im > 4)
		{
			color = get_color(k);
			return(my_pixel_put(args->img, i, j, color));
		}
	}
	return (my_pixel_put(args->img, i, j, 0x00000000));
}

int zoomm(int button,int  x, int y, t_args *args)
{
	double a;
	double b;

	a = x * (args->max_x - args->min_x) / 800 + args->min_x; 
	b = y * (args->max_y - args->min_y) / 800 + args->min_y;	
	if (button == 5)
	{
		// zoom in
		args->min_x = a + (args->min_x - a) / 1.25;
		args->min_y = b + (args->min_y - b) / 1.25;
		args->max_x = a + (args->max_x - a) / 1.25;
		args->max_y = b + (args->max_y - b) / 1.25;
		args->flag++;
		args->var = args->flag * 1.25;
	}
	if (button == 4)
	{
		args->min_x = a + (args->min_x - a) * 1.25;
		args->min_y = b + (args->min_y - b) * 1.25;
		args->max_x = a + (args->max_x - a) * 1.25;
		args->max_y = b + (args->max_y - b) * 1.25;
		args->flag = 2;
	}
	if (button == 4 || button == 5)
	{
		iterating(args);
		mlx_put_image_to_window(args->mlx, args->mlx_win, args->img->img, 1, 1);
	}
	printf("%d\n", button);
	return (0);
}

int key(int button, t_args *args)
{
	(void)args;
	if (button == 53)
	{
		// mlx_destroy_window(vars.mlx, vars.mlx_win);
		// free(vars.mlx);
		//printf("%d\n", button);
		exit(1);
	}
	double move = 1;
	if (args->var)
		move /= args->var;
	printf("%f\n", move);
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
	if (button == 124 || button == 123 || button == 126 || button == 125)
	{
		iterating(args);
		mlx_put_image_to_window(args->mlx, args->mlx_win, args->img->img, 1, 1);	
	}
	return (0);
}

void iterating(t_args *args)
{
	double x, y;
	int i = 0;
	int j = 0;
	for (i = 0; i < 800; i++)
	{
		for (j = 0; j < 800; j++)
		{
			x = i * (args->max_x - args->min_x) / 800 + args->min_x; 
			y = j * (args->max_y - args->min_y) / 800 + args->min_y;
			if (args->set == 2)
				plan_julia(x, y, args, i, j);
			else if (args->set == 1)
				plan(x, y, args, i, j);
			else
				ship(x, y, args, i , j);
		}
	}
}

int close(void *data)
{
	(void)data;
	exit(1);
	printf("closed");
	return (0);
}
// void begin(t_data *img, t_args *data)
// {
// 	t_data img;
// 	t_args data;
// 	data.min_x = -2;
// 	data.max_x = 2;
// 	data.min_y = -2;
// 	data.max_y = 2;	
// 	data.mlx = mlx_init();
//     data.mlx_win = mlx_new_window(data.mlx, 800, 800, "FRACTAL");
//     img.img = mlx_new_image(data.mlx, 800, 800);  
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// 	data.img = &img;
// 	iterating(&data);
// 	mlx_put_image_to_window(data.mlx, data.mlx_win, img.img, 1, 1);
// 	}

int main(int ac, char **av)
{
	t_data img;
	t_args data;
	data.min_x = -2;
	data.max_x = 2;
	data.min_y = -2;
	data.max_y = 2;
	if (ac == 2 && (ft_strcmp("Mandelbrot", av[1]) == 0))
		data.set= 1;
	else if (ac == 4 && (ft_strcmp("Julia", av[1]) == 0))
	{
		data.set = 2;
		data.a = atof(av[2]);
	 	data.b = atof(av[3]);
	}
	else if (ac == 2 && (ft_strcmp("Ship", av[1]) == 0))
		data.set = 3;
	else
		return (0);

    data.mlx = mlx_init();
    data.mlx_win = mlx_new_window(data.mlx, 800, 800, "FRACTAL");
    img.img = mlx_new_image(data.mlx, 800, 800);  
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	data.img = &img;
	iterating(&data);
	mlx_put_image_to_window(data.mlx, data.mlx_win, img.img, 1, 1);
	mlx_key_hook(data.mlx_win, key, &data);
	mlx_mouse_hook(data.mlx_win, zoomm, &data);
	mlx_hook(data.mlx_win, 17, 0, close, NULL);
	mlx_loop(data.mlx);
	system("leaks fractol");
}
