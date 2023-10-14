/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:09:16 by ojimenez          #+#    #+#             */
/*   Updated: 2023/10/14 17:56:43 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fr_destroy(t_fractal *f)
{
	if (f->win)
		mlx_destroy_window(f->mlx, f->win);
	if (f->imag)
		mlx_destroy_image(f->mlx, f->imag);
	if (f->mlx)
		free(f->mlx);
	free(f);
	f = NULL;
	exit(EXIT_FAILURE);
}

int	fr_read_keys_finish(int key_pressed, t_fractal *f)
{
	if (key_pressed == ESC)
		fr_destroy(f);
	return (0);
}

int	mouse_scroll(int param, int x, int y, t_fractal *f)
{
	y = 0;
	x = 0;
	if (param == 5)
		f->zoom = f->zoom * 0.95;
	else if (param == 4)
		f->zoom = f->zoom / 0.95;
	mlx_clear_window(f->mlx, f->win);
	draw_fractal(f, f->fract, f->params);
	return (0);
}

int	arrow_move(int key, t_fractal *f)
{
	if (key == ARROW_LEFT)
		f->offset_x += 0.1;
	if (key == ARROW_RIGHT)
		f->offset_x -= 0.1;
	if (key == ARROW_UP)
		f->offset_y += 0.1;
	if (key == ARROW_DOWN)
		f->offset_y -= 0.1;
	mlx_clear_window(f->mlx, f->win);
	draw_fractal(f, f->fract, f->params);
	return (0);
}

void	init_mlx(t_fractal *f)
{
	f->mlx = mlx_init();
	if (f->mlx == NULL)
		fr_destroy(f);
	f->win = mlx_new_window(f->mlx, SIZE, SIZE, f->params[1]);
	if (f->win == NULL)
		fr_destroy(f);
	f->imag = mlx_new_image(f->mlx, SIZE, SIZE);
	if (f->win == NULL)
		fr_destroy(f);
	f->addr = mlx_get_data_addr(f->imag, &f->bpp,
			&f->size_l, &f->endian);
	draw_fractal(f, f->fract, f->params);
	mlx_hook(f->win, 17, 0, fr_destroy, f);
	mlx_hook(f->win, 2, 0, fr_read_keys_finish, f);
	mlx_hook(f->win, 4, 0, mouse_scroll, f);
	mlx_key_hook(f->win, arrow_move, f);
	mlx_loop(f->mlx);
}
