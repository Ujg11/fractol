/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:08:35 by ojimenez          #+#    #+#             */
/*   Updated: 2023/10/06 18:34:54 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	f->fract = fract;
	if (f == NULL)
		return (0);
	f->params = argv;
	f->zoom = 1;
	f->max_iterations = MAX_ITERATIONS;
	init_mlx(f);
}
