#include <mlx.h>
#include <math.h>
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void my_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void plan (double *a, double *b, t_data *img, int *i, int *j)
{
	double z_im = *b;
	double z_r = *a;
	int k = 0;
	double temp;
	for (; k < 100; k++)
	{
		temp = 2 * z_im * z_r + *b;
		z_r = z_r * z_r  - z_im * z_im + *a;
		z_im = temp;
		if (z_r * z_r + z_im * z_im > 4)
		{
			return(my_pixel_put(img, *i, *j, 0x00C080FF));
		}
	}
	return (my_pixel_put(img, *i, *j, 0x00000000));
}
int main(void)
{
	t_data img;
	int i = 0;
	int j;
	double a = 0;
	double b = 0;
	double min = -2;
	double max = 2;
	// int min_im = -2;
	// int max_im = 2;
    void *mlx;
    void *mlx_win;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 800, 800, "FRACTAL");
    img.img = mlx_new_image(mlx, 800, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	for (; i < 800; i++)
	{
		for (j = 0; j < 800; j++)
		{
			a = i * (max - min) / 800 + min; 
			b = j * (max - min) / 800 + min;
			plan(&a, &b, &img, &i, &j);
		}
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	mlx_loop(mlx);
}
