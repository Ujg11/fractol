/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:24:17 by ojimenez          #+#    #+#             */
/*   Updated: 2023/10/14 18:14:28 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_julia(t_fractal *f, char **params)
{
	int		i;
	double	x_tmp;

	i = 0;
	f->cx = ft_strtod(params[2]);
	f->cy = ft_strtod(params[3]);
	f->zx = -2.0 + (double)f->x * (2.0 - (-2.0)) / SIZE + f->offset_x;
	f->zy = 2.0 + (double)f->y * (-2.0 - 2.0) / SIZE + f->offset_y;
	while (++i < MAX_ITERATIONS)
	{
		x_tmp = f->zx * f->zx - f->zy * f->zy + f->cx;
		f->zy = (2. * f->zx * f->zy + f->cy) * f->zoom;
		f->zx = x_tmp * f->zoom;
		if (f->zx * f->zx + f->zy * f->zy >= 4)
			break ;
	}
	if (i == MAX_ITERATIONS)
		put_color_to_pixel(f, 0x000);
	else
		put_color_to_pixel(f, i * 0x9f0f05f);
}

void	draw_mandelbrot(t_fractal *f)
{
	int		i;
	double	x_tmp;

	i = 0;
	f->cx = -2.0 + (double)f->x * (2.0 - (-2.0)) / SIZE + f->offset_x;
	f->cy = 2.0 + (double)f->y * (-2.0 - 2.0) / SIZE + f->offset_y;
	while (++i < MAX_ITERATIONS)
	{
		x_tmp = f->zx * f->zx - f->zy * f->zy + f->cx;
		f->zy = (2. * f->zx * f->zy + f->cy) * f->zoom;
		f->zx = x_tmp * f->zoom;
		if (f->zx * f->zx + f->zy * f->zy >= 4)
			break ;
	}
	if (i == MAX_ITERATIONS)
		put_color_to_pixel(f, 0x5fffff);
	else
		put_color_to_pixel(f, (i * 10) + 0x10ff);
}

void	draw_fractal(t_fractal *f, int fract, char **params)
{
	f->x = 0;
	f->y = 0;
	while (f->x < SIZE)
	{
		f->y = 0;
		while (f->y < SIZE)
		{
			if (fract == 1)
				draw_julia(f, params);
			else if (fract == 2)
			{
				f->zx = 0.0;
				f->zy = 0.0;
				draw_mandelbrot(f);
			}
			f->y++;
		}
		f->x++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->imag, 0, 0);
}
