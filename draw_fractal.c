/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:24:17 by ojimenez          #+#    #+#             */
/*   Updated: 2023/09/29 18:13:44 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_julia(t_fractal *f, char **params)
{
	(void)f;
	(void)params;
}

// De la formula varia la C y Z0 = 0
void	draw_mandelbrot(t_fractal *f, t_imag *imag)
{
	int		i;
	double	x_tmp;
	double	max_im;

	f->name = "Mandelbrot";
	i = 0;
	f->zx = 0.0;
	f->zy = 0.0;
	f->zoom = 1;
	f->cx = f->x / f->zoom;
	f->cy = f->y / f->zoom;
	max_im = -2.0 + (2.0 - (-2.0));
	(void)imag;
	f->max_iterations = 100;
	while (++i < f->max_iterations)
	{
		f->cx = (f->x - WIDTH / 2.0) / (0.5 * f->zoom * WIDTH);
		f->cy = (f->y - HEIGHT / 2.0) / (0.5 * f->zoom * HEIGHT);

		f->cx = -2.0 + (double)f->x * (2.0 - (-2.0)) / WIDTH;
		f->cy = max_im + (double)f->y * (-2.0 - 2.0) / HEIGHT;

		x_tmp = f->zx * f->zx - f->zy * f->zy + f->cx;
		f->zy = 2. * f->zx * f->zy + f->cy;
		f->zx = x_tmp;
		if (f->zx * f->zx + f->zy * f->zy >= 4)
			break ;
	}
	if (i == f->max_iterations)
	{
		mlx_pixel_put(f->mlx, f->win, f->x, f->y, 555555555);
	}
	else
	{
		//put_color_to_pixel(f, imag, (f->color * i));
		mlx_pixel_put(f->mlx, f->win, f->x, f->y, 1111111);
	}
}

void	draw_fractal(t_fractal *f, t_imag *imag, int fract, char **params)
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
				draw_mandelbrot(f, imag);
			f->y++;
		}
		f->x++;
		f->y = 0;
	}
	//mlx_put_image_to_window(f->mlx, f->win, f->imag, 0, 0);
}

/*int color = 0;  // Inicialización con color negro (todos los componentes en 0)

int red = 255;    // Valor de componente de rojo
int green = 128;  // Valor de componente de verde
int blue = 0;     // Valor de componente de azul

// Ajusta los componentes de color en el número de 24 bits
color |= (red << 16);    // Agrega el componente rojo
color |= (green << 8);   // Agrega el componente verde
color |= blue;           // Agrega el componente azul*/


/*void	draw_fractal(t_fractal *s, int fract)
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
}
*/