/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:08:35 by ojimenez          #+#    #+#             */
/*   Updated: 2023/09/29 16:02:29 by ojimenez         ###   ########.fr       */
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
	fract = check_arg(argv);
	if (fract == 0)
		return (0);
	f = (t_fractal *)malloc(sizeof(t_fractal));
	if (f == NULL)
		return (0);
	init_mlx(f, argv, fract);
}
