#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykaplien <ykaplien@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/22 17:07:00 by ykaplien          #+#    #+#              #
#    Updated: 2019/02/22 17:07:01 by ykaplien         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CFLAGS		= -Wall -Wextra -Werror
NAME		= wolf3d
SRC_NAME 	= main.c tools.c tools2.c tools3.c data.c data2.c event_handle.c proccesing.c proccesing2.c proccesing3.c
LIBFT_DIR	= ./libft/
LIBFT		= ./libft/libft.a
SRC			=$(addprefix ./srcs/, $(SRC_NAME))
OBJ			= $(SRC:%.c=%.o)

.PHONY: norm all re clean fclean

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	gcc $(CFLAGS) $(OBJ) -I ./includes -I /usr/local/include -I -r $(LIBFT) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -o $(NAME) -lm

%.o:%.c $(LIBFT) ./includes/wolf.h
	gcc $(CFLAGS) -c $< -o $@ -I ./includes

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all