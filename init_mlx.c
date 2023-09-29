/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:09:16 by ojimenez          #+#    #+#             */
/*   Updated: 2023/09/29 18:12:18 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fr_destroy(t_fractal *s)
{
	///free
	(void)s;
	exit(0);
}

int	fr_read_keys_finish(int key_pressed, t_fractal *s)
{
	if (key_pressed == ESC)
		fr_destroy(s);
	return (0);
}

int	mouse_scroll_up(int param, int x, int y, t_fractal *f)
{
	(void)f;
	y = 0;
	x = 0;
	if (param == 5)
		ft_printf("Cap amunt\n");
	if (param == 4)
		ft_printf("Cap avall\n");
	ft_printf("%d\n", param);
	exit(0);
}

/*int	mouse_click(t_fractal *s)
{
	(void)s;
	exit(0);
}*/

/*void	init_mlx(t_fractal *f, char **params, int fract)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, params[1]);
	f->imag->imag_ptr = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->imag->data = mlx_get_data_addr(f->imag->imag_ptr, &f->imag->bpp,
			&f->imag->size_l, &f->imag->endian);
	draw_fractal(f, fract, params);
	mlx_hook(f->win, 17, 0, fr_destroy, f);
	mlx_hook(f->win, 2, 0, fr_read_keys_finish, f);
	mlx_hook(f->win, 4, 0, mouse_scroll_up, f);
	//mlx_hook(f->win, 5, 0, mouse_click, &f);
	mlx_loop(f->mlx);
}*/

void	init_mlx(t_fractal *f, char **params, int fract)
{
	t_imag	*imag;

	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, 1080, 1080, params[1]);
	f->imag = mlx_new_image(f->mlx, 1080, 1080);
	imag = f->imag;
	imag->imag_ptr = f->imag;
	imag->data = mlx_get_data_addr(imag->imag_ptr, &imag->bpp,
			&imag->size_l, &imag->endian);
	draw_fractal(f, imag, fract, params);
	mlx_hook(f->win, 17, 0, fr_destroy, f);
	mlx_hook(f->win, 2, 0, fr_read_keys_finish, f);
	mlx_hook(f->win, 4, 0, mouse_scroll_up, f);
	//mlx_hook(f->win, 5, 0, mouse_click, &f);
	mlx_loop(f->mlx);
}
