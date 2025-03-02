/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrouk <mbrouk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:54:20 by mbrouk            #+#    #+#             */
/*   Updated: 2025/03/02 01:16:33 by mbrouk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_free_all(t_fractol *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img.img);
	mlx_destroy_window(fractal->mlx, fractal->win);
	mlx_destroy_display(fractal->mlx);
	ft_error(fractal);
}

void	ft_init_window(t_fractol *fractal)
{
	fractal->mlx = mlx_init();
	if (fractal->mlx == NULL)
		ft_error(fractal);
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, fractal->title);
	if (fractal->win == NULL)
	{
		mlx_destroy_display(fractal->mlx);
		ft_error(fractal);
	}
	fractal->img.img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (fractal->img.img == NULL)
	{
		mlx_destroy_window(fractal->mlx, fractal->win);
		mlx_destroy_display(fractal->mlx);
		ft_error(fractal);
	}
	fractal->img.pixel_addr = mlx_get_data_addr(fractal->img.img,
			&fractal->img.bits_pp, &fractal->img.line_length,
			&fractal->img.endian);
	if (fractal->img.pixel_addr == NULL)
		ft_free_all(fractal);
	ft_data_init(fractal);
	ft_events(fractal);
}

static void	ft_check_fractal_set(t_complex *z, t_complex *c, t_fractol *fractal)
{
	if (ft_strcmp(fractal->title, "julia") == 0)
	{
		c->reel = fractal->julia_reel;
		c->imaginary = fractal->julia_imaginary;
	}
	else
	{
		c->reel = z->reel;
		c->imaginary = z->imaginary;
	}
}

void	ft_pixel(int x, int y, t_fractol *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.reel = ft_scale(x, -2, 2, WIDTH) * fractal->zoom + fractal->shift_reel;
	z.imaginary = ft_scale(y, 2, -2, HEIGHT)
		* fractal->zoom + fractal->shift_imaginary;
	ft_check_fractal_set(&z, &c, fractal);
	while (i < fractal->iteration_num)
	{
		z = ft_sum_complex(ft_square_complex(z), c);
		if ((z.reel * z.reel + z.imaginary * z.imaginary) > 4)
		{
			color = ft_scale(i, BLACK, WHITE, fractal->iteration_num);
			ft_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	ft_pixel_put(x, y, &fractal->img, BLACK);
}

void	ft_render_fractal(t_fractol *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ft_pixel(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.img, 0, 0);
}
