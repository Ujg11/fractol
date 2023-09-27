/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:09:16 by ojimenez          #+#    #+#             */
/*   Updated: 2023/09/27 12:40:26 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fr_destroy(t_screen *s)
{
	///free
	(void)s;
	exit(0);
}

int	fr_game_read_keys_finish(int key_pressed, t_screen *s)
{
	if (key_pressed == ESC)
		fr_destroy(s);
	return (0);
}

void	init_mlx(t_screen *s, char *name, int fact)
{
	s->mlx = mlx_init();
	s->win = mlx_new_window(s->mlx, 1080, 1080, name);
	fact = 0;
	mlx_hook(s->win, 17, 0, fr_destroy, &s); // x de cerrar ventana
	mlx_hook(s->win, 2, 0, fr_game_read_keys_finish, &s); // este hace un bucle while 2 con teclas
	mlx_loop(s->mlx);
}
