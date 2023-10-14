/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:08:35 by ojimenez          #+#    #+#             */
/*   Updated: 2023/10/14 18:07:37 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_structure(t_fractal *f, int fract, char **argv)
{
	f->fract = fract;
	f->params = argv;
	f->zoom = 1;
	f->offset_x = 0;
	f->offset_y = 0;
}

int	main(int argc, char *argv[])
{
	t_fractal	*f;
	int			fract;

	if (argc < 2)
	{
		print_init_fractol();
		return (0);
	}
	fract = check_arg(argv, argc);
	f = (t_fractal *)malloc(sizeof(t_fractal));
	if (f == NULL)
		return (0);
	init_structure(f, fract, argv);
	init_mlx(f);
}
