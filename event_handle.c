/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrouk <mbrouk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:19:16 by mbrouk            #+#    #+#             */
/*   Updated: 2025/02/27 17:56:35 by mbrouk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_close_win(t_fractol *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img.img);
	mlx_destroy_window(fractal->mlx, fractal->win);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit(0);
	return (0);
}

static int	ft_handle_key_events(int keycode, t_fractol *fractal)
{
	if (keycode == KEY_ESC)
		ft_close_win(fractal);
	else if (keycode == KEY_LEFT)
		fractal->shift_reel -= 0.1 * fractal->zoom;
	else if (keycode == KEY_UP)
		fractal->shift_imaginary += 0.1 * fractal->zoom;
	else if (keycode == KEY_RIGHT)
		fractal->shift_reel += 0.1 * fractal->zoom;
	else if (keycode == KEY_DOWN)
		fractal->shift_imaginary -= 0.1 * fractal->zoom;
	else if (keycode == KEY_PLUS)
		fractal->iteration_num += 3;
	else if (keycode == KEY_MINUS)
		fractal->iteration_num -= 3;
	mlx_clear_window(fractal->mlx, fractal->win);
	ft_render_fractal(fractal);
	return (0);
}

static int	ft_mouse_event(int mouse_code, int x, int y, t_fractol *fractal)
{
	(void)x;
	(void)y;
	if (mouse_code == 4)
		fractal->zoom *= 0.80;
	else if (mouse_code == 5)
		fractal->zoom *= 1.20;
	mlx_clear_window(fractal->mlx, fractal->win);
	ft_render_fractal(fractal);
	return (0);
}

void	ft_events(t_fractol *fractal)
{
	mlx_key_hook(fractal->win, ft_handle_key_events, fractal);
	mlx_hook(fractal->win, 17, 0, ft_close_win, fractal);
	mlx_mouse_hook(fractal->win, ft_mouse_event, fractal);
}
