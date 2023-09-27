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

