# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knikogho <knikogho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/23 13:43:02 by knikogho          #+#    #+#              #
#    Updated: 2022/10/23 13:43:11 by knikogho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = moving_rainbow.c

NAME = moving_rainbow


OBJ = moving_rainbow.o

CC = cc
%.o: %.c
		$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)


clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(OBJ) $(NAME)

re: fclean all

.PHONY: all re fclean clean

