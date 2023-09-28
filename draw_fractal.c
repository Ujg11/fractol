/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:24:17 by ojimenez          #+#    #+#             */
/*   Updated: 2023/09/27 15:35:38 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_julia(t_fractal *f, char **params)
{
	
}

// De la formula varia la C y Z0 = 0
void	draw_mandelbrot(t_fractal *f)
{
	int		i;
	double	x_tmp;

	f->name = "Mandelbrot";
	i = 0;
	f->zx = 0.0;
	f->zy = 0.0;
	f->cx = f->x / f->zoom;
	f->cy = f->y / f->zoom;
	while (++i < f->max_iterations)
	{
		x_tmp = f->zx * f->zx - f->zy * f->zy + f->cx;
		f->zy = 2. * f->zx * f->zy + f->cy;
		f->zx = x_tmp;
		if (f->zx * f->zx + f->zy * f->zy >= __DBL_MAX__)
			break ;
	}
}

void	draw_fractal(t_fractal *f, int fract, char **params)
{
	f->x = 0;
	f->y = 0;
	while (f->x < 1080)
	{
		while (f->y < 1080)
		{
			if (fract == 1)
				draw_julia(f, params);
			else if (fract == 2)
				draw_mandelbrot(f);
			f->y++;
		}
		f->x++;
		f->y = 0;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->imag, 0, 0);
}

/*void    draw_fractol(t_screen *s, int fract)
{
	(void)fract;
	double radius = 100.0;  // Radio del círculo
	double angle = 0.0;

	while (angle < 2.0 * M_PI)  // Recorre el círculo completo (360 grados)
	{
		double x = radius * cos(angle) + 300;  // Calcula la coordenada x
		double y = radius * sin(angle) + 300;  // Calcula la coordenada y

		mlx_pixel_put(s->mlx, s->win, (int)x, (int)y, 1000);

		x = (radius + 500) * cos(angle) + 900;  // Calcula la coordenada x
		y = radius * sin(angle) + 500;  // Calcula la coordenada y

		mlx_pixel_put(s->mlx, s->win, (int)x, (int)y, 56789);

		angle += 0.01;  // Aumenta el ángulo en pequeños incrementos
	}
}*/