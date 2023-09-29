# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/20 12:55:07 by ojimenez          #+#    #+#              #
#    Updated: 2023/09/29 15:39:04 by ojimenez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc
CFLAGS = -Wall -Wextra -Werror 
#-fsanitize=address -g
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

MLX_PATH = ./mlx
MLX = $(MLX_PATH)/libmlx.a

OBJECTS = main.o init_mlx.o check_arg.o draw_fractal.o

all: ${NAME}

$(LIBFT):
	$(MAKE) -s -C $(LIBFT_PATH) all

$(MLX):
	$(MAKE) -s -C $(MLX_PATH) all

$(NAME): $(OBJECTS) $(LIBFT) $(MLX) Makefile
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) -Ilibft/ -Llibft/ -lft \
	-Imlx/ -Lmlx/ -lmlx -framework OpenGL -framework AppKit -lm
	@printf "\n$(COLOR)$(KAOMOJI_SUCCESS) Successfully compiled!$(COLOR_RESET)"

%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@ -Iinclude/libft/include -Iinclude/mlx
	
clean:
	rm -f $(NAME)
	$(MAKE) -s -C $(LIBFT_PATH) clean
	$(MAKE) -s -C $(MLX_PATH) clean

fclean: clean
	@rm -f $(OBJECTS)
	$(MAKE) -s -C $(LIBFT_PATH) fclean

	
re: fclean all

.PHONY: re all clean fclean