# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/04 18:00:32 by juthomas          #+#    #+#              #
#    Updated: 2017/04/13 21:49:35 by juthomas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all fclean clean re

NAME = fractol

SRC = fractol_main.c fractol_color_1.c fractol_color_2.c \
fractol_mandelbrot.c fractol_julia.c fractol_burning_ship.c \
fractol_fractale_4.c fractol_main_norm_1.c fractol_main_norm_2.c \
fractol_main_norm_3.c

LIB = libft/libft.a

CFLAGS = -O2 -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME):	$(OBJ)
	make -C libft/
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIB) -lmlx -framework OpenGL -framework AppKit

clean :
	make -C libft/ fclean
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
