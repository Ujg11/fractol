/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:29:41 by ojimenez          #+#    #+#             */
/*   Updated: 2023/10/13 14:55:14 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_color_to_pixel(t_fractal *f, int color)
{
	char	*dst;

	dst = f->addr + (f->y * f->size_l + f->x * (f->bpp / 8));
	*(unsigned int *)dst = color;
}
