# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhaukile <jhaukile@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 18:49:50 by jhaukile          #+#    #+#              #
#    Updated: 2022/03/03 09:56:16 by jhaukile         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
srcs =ft_memmove.c\
ft_putstr.c \
ft_strdel.c \
ft_strlen.c \
ft_strnew.c
OBJS = $(srcs:.c=.o)
all: $(NAME)

$(NAME): $(srcs) $(OBJS)
		gcc -Wall -Wextra -Werror -c $(srcs)
		ar rc $(NAME) $(OBJS)
clean:
	/bin/rm -f $(OBJS)
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all
