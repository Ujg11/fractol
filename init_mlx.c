#include "fractol.h"

void	init_mlx(t_screen *s, char *name, int fact)
{
	s->mlx = mlx_init();
	s->win = mlx_new_window(s->mlx, 1080, 1080, name);

}