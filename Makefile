# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhaukile <jhaukile@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 13:08:16 by jhaukile          #+#    #+#              #
#    Updated: 2022/03/03 09:53:09 by jhaukile         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
LIB = libft/libft.a
HEADER = fillit_header.h

srcs += main.c
srcs += map.c
srcs += errors.c
srcs += shapes.c
srcs += solver.c

OBJ = $(srcs:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(LIB):
	make -C libft

$(NAME): $(LIB) $(OBJ) $(srcs)
	$(CC) $(CFLAGS) $(srcs) -I $(HEADER) $(LIB) -o $(NAME)

clean:
	@rm -rf $(OBJ)
	@make -C libft clean

fclean: clean
	@rm -rf $(NAME) $(LIB)

re: fclean all
