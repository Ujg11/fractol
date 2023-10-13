/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:52:04 by ojimenez          #+#    #+#             */
/*   Updated: 2023/10/13 16:52:49 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_strtod(const char *str)
{
	double	num;
	int		i;
	int		neg;
	double	decimal;

	i = 0;
	neg = 1;
	decimal = 1.0;
	num = 0.0;
	if (str[i++] == '-')
		neg = -1;
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (str[i++] == '.')
	{
		while (str[i] >= '0' && str[i] <= '9')
		{
			decimal *= 0.1;
			num = num + (str[i] - '0') * decimal;
			i++;
		}
	}
	return (num * neg);
}
