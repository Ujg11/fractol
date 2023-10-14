/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:52:04 by ojimenez          #+#    #+#             */
/*   Updated: 2023/10/14 18:30:21 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_neg_or_pos(const char *str, int *i)
{
	int	neg;

	neg = 1;
	if (str[*i] == '-')
	{
		neg = -1;
		(*i)++;
	}
	else if (str[*i] == '+')
		(*i)++;
	return (neg);
}

double	ft_strtod(const char *str)
{
	double	num;
	int		i;
	int		neg;
	double	decimal;

	i = 0;
	neg = is_neg_or_pos(str, &i);
	decimal = 1.0;
	num = 0.0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (double)(str[i] - '0');
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			decimal *= 0.1;
			num = num + (str[i] - '0') * decimal;
			i++;
		}
	}
	return (num * neg);
}
