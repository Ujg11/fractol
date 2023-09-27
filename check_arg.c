#include "fractol.h"

void	print_init_fractol(void)
{
	ft_printf("Debes ejecutar el programa con el nombre del fractal que desees visualizar\n");
	ft_printf("Fractales disponibles: Julia y Mandelbrot\n");
	exit(0);
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (42);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	check_arg(char *name)
{
	if (ft_strcmp(name, "Julia") != 0 && ft_strcmp(name, "Mandelbrot") != 0)
		print_init_fractol();
	if (ft_strcmp(name, "Julia") == 0)
		return (1);
	else if (ft_strcmp(name, "Mandelbrot") != 0)
		return (2);
	return (0);
}
