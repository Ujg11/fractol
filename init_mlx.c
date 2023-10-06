/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:09:16 by ojimenez          #+#    #+#             */
/*   Updated: 2023/10/04 13:21:52 by ojimenez         ###   ########.fr       */
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

int	mouse_scroll_up(int param, int x, int y, t_fractal *f)
{
	(void)f;
	y = 0;
	x = 0;
	if (param == 5)
	{
		f->zoom = f->zoom + 100;
		//ft_printf("Cap amunt\n");
	}
	else if (param == 4)
	{
		f->zoom = f->zoom - 100;
		//ft_printf("Cap avall\n");
	}
	draw_fractal(f, f->timag, f->fract, f->params);
	//return (0);
	exit(0);
}

/*int	mouse_click(t_fractal *s)
{
	(void)s;
	exit(0);
}*/

void	init_mlx(t_fractal *f)
{
	f->mlx = mlx_init();
	if (f->mlx == NULL)
		fr_destroy(f);
	f->win = mlx_new_window(f->mlx, 1080, 1080, f->params[1]);
	if (f->win == NULL)
		fr_destroy(f);
	f->imag = mlx_new_image(f->mlx, 1080, 1080);
	if (f->win == NULL)
		fr_destroy(f);
	f->timag = f->imag;
	f->timag->data = mlx_get_data_addr(f->imag, &(f->timag->bpp),
			&(f->timag->size_l), &(f->timag->endian));
	draw_fractal(f, f->timag, f->fract, f->params);
	mlx_hook(f->win, 17, 0, fr_destroy, f);
	mlx_hook(f->win, 2, 0, fr_read_keys_finish, f);
	mlx_hook(f->win, 4, 0, mouse_scroll_up, f);
	//mlx_hook(f->win, 5, 0, mouse_click, &f);
	mlx_loop(f->mlx);
}
