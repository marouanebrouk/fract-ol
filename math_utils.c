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
