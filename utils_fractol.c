#include "fractol.h"

void ft_adjust_name(char *str)
{
    int i = 0;
    while (str[i])
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        i++;
    }
}

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	if (!s1[i] && !s2[i])
		return (-1);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
void    ft_print_error()
{
	int i;

	i = 0;
    char *str = "Error. \nFormat required:      < ./fractol mandelbrot >    OR    < ./fractol julia 'reel' 'imaginary' >\n";
    while (str[i])
    {
        write(2,&str[i],1);
        i++;
    }
	exit(1);
}

void ft_error(t_fractol *fractal)
{
    write(2,"mlx function failed\n",20);
    free(fractal->mlx);
    exit(1);
}


void ft_data_init(t_fractol *fractal)
{
    fractal->escape_value = 4; // 2 ^ 2 my hypothenus
    fractal->iteration_num = 120;
    fractal->shift_reel = 0.0;
    fractal->shift_imaginary = 0.0;
}