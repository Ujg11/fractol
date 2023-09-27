/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:11:47 by ojimenez          #+#    #+#             */
/*   Updated: 2023/09/27 12:12:33 by ojimenez         ###   ########.fr       */
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
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_UP 126
# define ARROW_DOWN 125
# define A 0
# define W 13
# define S 1
# define D 2

typedef struct s_screen
{
	int				x;
	int				y;
	void			*mlx;
	void			*win;

}					t_screen;

//check_arg.c
void	print_init_fractol(void);
int		check_arg(char *name);

//init_mlx.c
void	init_mlx(t_screen *s, char *name, int fact);

#endif
