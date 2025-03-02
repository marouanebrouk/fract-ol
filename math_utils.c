/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrouk <mbrouk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:00:17 by mbrouk            #+#    #+#             */
/*   Updated: 2025/02/27 22:58:21 by mbrouk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	ft_sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.reel = z1.reel + z2.reel;
	result.imaginary = z1.imaginary + z2.imaginary;
	return (result);
}

t_complex	ft_square_complex(t_complex z)
{
	t_complex	result;

	result.reel = (z.reel * z.reel) - (z.imaginary * z.imaginary);
	result.imaginary = 2 * z.reel * z.imaginary;
	return (result);
}

double	ft_scale(double num, double new_min, double new_max, double old_max)
{
	return (new_min + ((num - 0) * (new_max - new_min)) / (old_max - 0));
}

void	ft_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_length) + (x * (img->bits_pp / 8));
	*(int *)(img->pixel_addr + offset) = color;
}
