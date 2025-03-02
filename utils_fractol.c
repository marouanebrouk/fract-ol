/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fractol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrouk <mbrouk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:50:26 by mbrouk            #+#    #+#             */
/*   Updated: 2025/02/28 21:57:54 by mbrouk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_adjust_name(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1[i] && !s2[i])
		return (-1);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_print_error(void)
{
	int		i;
	char	*str;

	i = 0;
	str = "Error.\nFormat required: < ./fractol mandelbrot > OR "
		"< ./fractol julia 'reel' 'imaginary' >\n";
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	exit(1);
}

void	ft_error(t_fractol *fractal)
{
	write(2, "mlx function failed\n", 20);
	free(fractal->mlx);
	exit(1);
}

void	ft_data_init(t_fractol *fractal)
{
	fractal->iteration_num = 50;
	fractal->shift_reel = 0.0;
	fractal->shift_imaginary = 0.0;
	fractal->zoom = 1.0;
}
