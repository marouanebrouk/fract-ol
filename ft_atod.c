/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrouk <mbrouk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:14:07 by mbrouk            #+#    #+#             */
/*   Updated: 2025/02/27 15:14:09 by mbrouk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_is_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			ft_print_error();
		i++;
	}
}

double	ft_atod(char *str)
{
	long	decimal_result;
	double	double_result;
	double	fp;
	int		sign;

	decimal_result = 0;
	double_result = 0;
	fp = 1;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	while (*str >= '0' && *str <= '9')
		decimal_result = decimal_result * 10 + (*str++ - '0');
	if (*str == '.')
		str++;
	ft_is_valid(str);
	while (*str)
	{
		fp /= 10;
		double_result = double_result + (*str++ - '0') * fp;
	}
	return ((decimal_result + double_result) * sign);
}
