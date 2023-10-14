/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:11:47 by ojimenez          #+#    #+#             */
/*   Updated: 2023/10/14 17:29:33 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <limits.h>
# include <math.h>
# include "libft/libft.h"
# include "mlx/mlx.h"

# define ESC 53
# define MAX_ITERATIONS 100
# define SIZE 900

# define ARROW_LEFT 124
# define ARROW_RIGHT 123
# define ARROW_UP 126
# define ARROW_DOWN 125
# define A 0
# define W 13
# define S 1
# define D 2

typedef struct s_fractal
{
	int				x;
	int				y;
	double			zx;
	double			zy;
	double			cx;
	double			cy;
	int				color;
	double			zoom;
	int				fract;
	float			offset_x;
	float			offset_y;
	char			**params;
	void			*mlx;
	void			*win;
	void			*imag;
	char			*addr;
	int				size_l;
	int				bpp;
	int				endian;
}	t_fractal;

//check_arg.c
void	print_init_fractol(void);
int		check_arg(char **param, int argc);

//init_mlx.c
void	init_mlx(t_fractal *f);
int		fr_destroy(t_fractal *f);

//draw_fractol.c
void	draw_fractal(t_fractal *f, int fract, char **params);
void	recalculate_fract(t_fractal *f, double zoom, int x, int y);

//put_colors.c
void	put_color_to_pixel(t_fractal *f, int color);

//utils.c
double	ft_strtod(const char *str);

#endif
