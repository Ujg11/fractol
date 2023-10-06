/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:29:41 by ojimenez          #+#    #+#             */
/*   Updated: 2023/10/06 18:43:45 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_color_to_pixel(t_fractal *f, t_imag *imag, int color)
{
	ft_memcpy(imag->data + (f->y * imag->size_l + f->x
			* (imag->bpp / 8)), &color, sizeof(int));
}

/*void	put_color_to_pixel(t_fractal *f, t_imag *imag, int color)
{
	unsigned int	*pixels;
	int				index;

	index = 0;
	pixels = (unsigned int *)imag->data;
	if (f->x >= 0 && f->x < WIDTH && f->y >= 0 && f->y < HEIGHT)
	{
		index = f->y * (imag->size_l) / (imag->bpp / 8) + f->x;
		pixels[index] = color;
	}
}*/
