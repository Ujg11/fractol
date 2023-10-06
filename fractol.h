/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:11:47 by ojimenez          #+#    #+#             */
/*   Updated: 2023/10/06 17:56:10 by ojimenez         ###   ########.fr       */
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

# define ESC	53
# define MAX_ITERATIONS 100
# define WIDTH 1080
# define HEIGHT 1080

# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_UP 126
# define ARROW_DOWN 125
# define A 0
# define W 13
# define S 1
# define D 2

typedef struct	s_imag
{
	void	*imag_ptr;// Puntero a la imagen
	char	*data;// Datos de la imagen (bits)
	int		size_l;// Tamaño de línea (número de bytes en una línea de la imagen)
	int		bpp;// Bits por píxel
	int		endian;// Endian
}	t_imag;

typedef struct s_fractal
{
	int				x;
	int				y;
	double			zx;
	double			zy;
	double			cx;
	double			cy;
	int				max_iterations;
	int				color;
	double			zoom;
	int				fract;
	char			**params;
	void			*mlx;
	void			*win;
	void			*imag;
	t_imag			*timag;
}	t_fractal;

//check_arg.c
void	print_init_fractol(void);
int		check_arg(char **param, int argc);

//init_mlx.c
void	init_mlx(t_fractal *f);

//draw_fractol.c
void	draw_fractal(t_fractal *f, int fract, char **params);
void	recalculate_fract(t_fractal *f, double zoom, int x, int y);

//put_colors.c
void	put_color_to_pixel(t_fractal *f, t_imag *imag, int color);

#endif
