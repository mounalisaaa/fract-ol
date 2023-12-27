#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fractol.h"
int power_of(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(str[i])
		i++;
	j = i - 1;
	while(i - 1 > 0)
	{
		if (str[i] == '.')
			return (j - i);
		i--;
	}
	return (0);
}

int is_space(char c)
{
	return (c == ' ' || c == '\t');
}

double ft_atof(char *str)
{
	int i;
	double res;
	int flag;
	int sign ;

	flag = 0;
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
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
	{
		if (str[i] == '.')
		{
			if (flag)
			{
				//invalid use
				return (0);
			}
			i++;
			flag = 1;
		}

		res = (res * 10 ) + str[i++] - '0';
	}
	if (flag)
		res = res / pow(10.0, (double)power_of(str));
	return (res  * sign );
}

// int main ()
// {
//     double i = 0.8;
//     printf("%f\n", i);
// }