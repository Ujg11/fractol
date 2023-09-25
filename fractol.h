#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <limits.h>
# include <math.h>
//# include <libft.h>
# include <mlx.h>

typedef struct		s_screen
{
	int				x;
	int				y;
	void			*mlx;
	void			*win;

}					t_screen;

//check_arg.c
void	print_init_fractol(void);
int		check_arg(char *name);

//init_mlx.c
void	init_mlx(t_screen *s, char *name, int fact);

#endif