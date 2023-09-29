/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:09:16 by ojimenez          #+#    #+#             */
/*   Updated: 2023/09/29 16:02:13 by ojimenez         ###   ########.fr       */
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

void	init_mlx(t_fractal *f, char **params, int fract)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, 1080, 1080, params[1]);
	f->imag = mlx_new_image(f->mlx, 1080, 1080);
	draw_fractal(f, fract, params);
	mlx_hook(f->win, 17, 0, fr_destroy, &f);
	mlx_hook(f->win, 2, 0, fr_read_keys_finish, &f);
	mlx_hook(f->win, 4, 0, mouse_scroll_up, &f);
	//mlx_hook(f->win, 5, 0, mouse_click, &f);
	mlx_loop(f->mlx);
}
