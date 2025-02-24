#include "fractol.h"


t_complex sum_comlpex(t_complex z1, t_complex z2)
{
    t_complex result;

    result.reel = z1.reel + z2.reel;
    result.imaginary = z1.imaginary + z2.imaginary;

    return (result);
}


t_complex square_complex(t_complex z)
{
    t_complex result;

    result.reel = (z.reel * z.reel) - (z.imaginary * z.imaginary);
    result.imaginary = 2 * z.reel * z.imaginary;
    return (result);
}



/*
 * [0..799] -> [-2..+2]
 *
 * linear interpolation formula
*/
double ft_scale(double num, double new_min, double new_max, double old_min, double old_max)
{
    return ( new_min +  (num - old_min) * (new_max - new_min) / (old_max - old_min));
}



void	ft_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_length) + (x * (img->bits_pp / 8));
	*(int *)(img->pixel_addr + offset) = color;
}



double ft_atod(char *str)
{
    long decimal_result;
    double floating_result;
    double fp;
    int sign;

    (1) & (decimal_result = 0, floating_result = 0,fp = 1,sign = 1);
    while ((*str >= 9 && *str <= 13 )|| *str == 32)
        str++;
    if (*str == '-'  || *str == '+')
        if(*str++ == '-')
            sign *= -1;
    while (*str >= '0' && *str <= '9')
    {
        decimal_result = decimal_result * 10 + (*str - '0');
        str++;
    }
    if (*str == '.')
        str++;
    while(*str)
    {
        fp /= 10;
        floating_result = floating_result + (*str - '0') * fp;
        str++;
    }
    return ((decimal_result + floating_result) * sign);
}

