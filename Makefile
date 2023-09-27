# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/20 12:55:07 by ojimenez          #+#    #+#              #
#    Updated: 2023/09/27 12:03:51 by ojimenez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

OBJECTS = main.c init_mlx.c check_arg.c

all: 
	@$(MAKE) -sC libft
	@$(MAKE) -sC mlx
	@$(MAKE) ${NAME} --no-print-directory

$(LIBFT):
	$(MAKE) -s -C $(LIBFT_PATH) all

${NAME}: ${OBJECTS} ${HEADERS} Makefile ${LIBFT} ${MLX}
	@gcc $(CFLAGS) -o ${NAME} ${OBJECTS} -Ilibft/ -Llibft/ -lft \
	-Imlx/ -Lmlx/ -lmlx -framework OpenGL -framework AppKit
	@printf "\n$(COLOR)$(KAOMOJI_SUCCESS) Successfully compiled!$(COLOR_RESET)"

%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@ -Iinclude/libft/include -Iinclude/mlx
	
clean:
	rm -f $(OBJECTS)
	$(MAKE) -s -C $(LIBFT_PATH) clean

fclean: clean
	@rm -rf ${BINDIR}
	@$(MAKE) -C libft fclean
	@$(MAKE) -C mlx clean
re: fclean all

.PHONY: re all clean fclean