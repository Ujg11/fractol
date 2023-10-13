/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:24:17 by ojimenez          #+#    #+#             */
/*   Updated: 2023/10/13 16:55:54 by ojimenez         ###   ########.fr       */
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
	f->zx = -2.0 + (double)f->x * (2.0 - (-2.0)) / SIZE;
	f->zy = 2.0 + (double)f->y * (-2.0 - 2.0) / SIZE;
	while (++i < MAX_ITERATIONS)
	{
		x_tmp = f->zx * f->zx - f->zy * f->zy + f->cx;
		f->zy = (2. * f->zx * f->zy + f->cy) * f->zoom;
		f->zx = x_tmp * f->zoom;
		if (f->zx * f->zx + f->zy * f->zy >= 4)
			break ;
	}
	if (i == MAX_ITERATIONS)
	{
		//mlx_pixel_put(f->mlx, f->win, f->x, f->y, 0x000000);
		put_color_to_pixel(f, 0x00000);
	}
	else
	{
		//mlx_pixel_put(f->mlx, f->win, f->x, f->y, (i + 20) * 1111111);
		put_color_to_pixel(f, (i % 4599) * 999999);
	}
}

void	draw_mandelbrot(t_fractal *f)
{
	int		i;
	double	x_tmp;

	i = 0;
	f->zx = 0.0;
	f->zy = 0.0;
	f->cx = -2.0 + (double)f->x * (2.0 - (-2.0)) / SIZE;
	f->cy = 2.0 + (double)f->y * (-2.0 - 2.0) / SIZE;
	while (++i < MAX_ITERATIONS)
	{
		x_tmp = f->zx * f->zx - f->zy * f->zy + f->cx;
		f->zy = (2. * f->zx * f->zy + f->cy) * f->zoom;
		f->zx = x_tmp * f->zoom;
		if (f->zx * f->zx + f->zy * f->zy >= 4)
			break ;
	}
	if (i == MAX_ITERATIONS)
	{
		put_color_to_pixel(f, 0x00000);
		//mlx_pixel_put(f->mlx, f->win, f->x, f->y, 0x000000);
	}
	else
	{
		put_color_to_pixel(f, i * 0xFCBE11);
		//mlx_pixel_put(f->mlx, f->win, f->x, f->y, (i + 20) * 1111111);
	}
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
				draw_mandelbrot(f);
			}
			f->y++;
		}
		f->x++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->imag, 0, 0);
}
