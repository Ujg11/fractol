#include "fractol.h"

int main(int argc, char *argv[])
{
	t_screen	*s;
	int			fract;


	if (argc != 2)
	{
		print_init_fractol();
		return (0);
	}
	fract = check_arg(argv[1]);
	s = (t_screen *)malloc(sizeof(t_screen));
	if (s == NULL)
		return (0);
	init_mlx(s, argv[1], fract);
}