/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:08:59 by ojimenez          #+#    #+#             */
/*   Updated: 2023/10/14 18:10:30 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_init_fractol(void)
{
	ft_printf("Debes ejecutar el programa con el nombre");
	ft_printf("del fractal que desees visualizar\n");
	ft_printf("Fractales disponibles:\n--Julia cx cy--\n--Mandelbrot--\n");
	exit(0);
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (42);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	is_digit(char *s)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (s[0] == '-' || s[0] == '+')
		i++;
	if (!s[0])
		return (0);
	while (s[i])
	{
		if (s[i] == '.' && flag == 1)
			print_init_fractol();
		else if (s[i] == '.' && flag == 0)
			flag = 1;
		else if (s[i] < '0' || s[i] > '9')
			print_init_fractol();
		i++;
	}
	return (1);
}

int	check_arg(char **param, int argc)
{
	if (ft_strcmp(param[1], "Julia") != 0
		&& ft_strcmp(param[1], "Mandelbrot") != 0)
		print_init_fractol();
	else if (ft_strcmp(param[1], "Mandelbrot") == 0 && argc == 2)
		return (2);
	else if (ft_strcmp(param[1], "Julia") == 0 && argc != 4)
		print_init_fractol();
	else if (ft_strcmp(param[1], "Julia") == 0 && argc == 4)
	{
		if (is_digit(param[2]) && is_digit(param[3]))
			return (1);
	}
	else
		print_init_fractol();
	return (0);
}
