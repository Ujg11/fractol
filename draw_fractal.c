/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:24:17 by ojimenez          #+#    #+#             */
/*   Updated: 2023/10/06 18:46:35 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	recalculate_fract(t_fractal *f, double zoom, int x, int y)
{
	x = 0;
	y = 0;
	f->cx = -2.0 + (double)f->x * (2.0 - (-2.0)) / zoom;
	f->cy = 2.0 + (double)f->y * (-2.0 - 2.0) / zoom;
	draw_fractal(f, f->fract, f->params);
}

void	draw_julia(t_fractal *f, char **params, t_imag *imag)
{
	int		i;
	double	x_tmp;
	//(void)f;
	//(void)params;
	f->cx = ft_atoi(params[2]);
	f->cy = ft_atoi(params[3]);
	f->zx = -2.0 + (double)f->x * (2.0 - (-2.0)) / WIDTH;
	f->zy = f->cy = 2.0 + (double)f->y * (-2.0 - 2.0) / HEIGHT;
	while (++i < f->max_iterations)
	{
		x_tmp = f->zx * f->zx - f->zy * f->zy + f->cx;
		f->zy = (2. * f->zx * f->zy + f->cy) * f->zoom;
		f->zx = x_tmp * f->zoom;
		if (f->zx * f->zx + f->zy * f->zy >= 4)
			break ;
	}
	if (i == f->max_iterations)
	{
		//mlx_pixel_put(f->mlx, f->win, f->x, f->y, 0x000000);
		put_color_to_pixel(f, imag, 0xFFFFFF);
	}
	else
	{
		put_color_to_pixel(f, imag, (i+456) * 999999);
		//(void)imag;
		//mlx_pixel_put(f->mlx, f->win, f->x, f->y, (i + 20) * 1111111);
	}

}

// De la formula varia la C y Z0 = 0
void	draw_mandelbrot(t_fractal *f, t_imag *imag)
{
	int		i;
	double	x_tmp;

	i = 0;
	f->zx = 0.0;
	f->zy = 0.0;
	f->cx = -2.0 + (double)f->x * (2.0 - (-2.0)) / WIDTH;
	f->cy = 2.0 + (double)f->y * (-2.0 - 2.0) / HEIGHT;
	while (++i < f->max_iterations)
	{
		x_tmp = f->zx * f->zx - f->zy * f->zy + f->cx;
		f->zy = (2. * f->zx * f->zy + f->cy) * f->zoom;
		f->zx = x_tmp * f->zoom;
		if (f->zx * f->zx + f->zy * f->zy >= 4)
			break ;
	}
	if (i == f->max_iterations)
	{
		//mlx_pixel_put(f->mlx, f->win, f->x, f->y, 0x000000);
		put_color_to_pixel(f, imag, 0xFFFFFF);
	}
	else
	{
		put_color_to_pixel(f, imag, (i+456) * 999999);
		//(void)imag;
		//mlx_pixel_put(f->mlx, f->win, f->x, f->y, (i + 20) * 1111111);
	}
}

void	draw_fractal(t_fractal *f, int fract, char **params)
{
	f->x = 0;
	f->y = 0;
	while (f->x < WIDTH)
	{
		while (f->y < HEIGHT)
		{
			if (fract == 1)
				draw_julia(f, params, f->imag);
			else if (fract == 2)
				draw_mandelbrot(f, f->imag);
			f->y++;
		}
		f->x++;
		f->y = 0;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->imag, 0, 0);
}
