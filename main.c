/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:08:35 by ojimenez          #+#    #+#             */
/*   Updated: 2023/09/27 12:08:37 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char *argv[])
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
