# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/15 18:28:13 by brvalcas          #+#    #+#              #
#    Updated: 2018/05/30 15:55:59 by adstuder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIB = fillit.a

SRC = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strdup.c\
	srcs/ft_strlen.c srcs/get_next_piece.c srcs/library_generator.c\
	srcs/parsing.c srcs/smallest_square.c srcs/tab_creator.c srcs/tetricmp.c\
	srcs/etridetector.c srcs/database_creation.c srcs/recursive.c\
	srcs/place_piece.c srcs/main.c

OBJET = $(SRC:.c=.o)

HEAD = -I includes/fillit.h

FLAG = -Wall -Wextra -Werror

DEBUG = -fsanitize=address

all : $(NAME)

%.o:%.c %.h
	@gcc $(FLAG) -o $@ -c $<

$(NAME) : $(OBJET)
	@ar rc $(LIB) $^
	@ranlib $(LIB)
	@gcc $(FLAG) $(LIB) -o $(NAME)

exe : $(NAME)
	time ./$(NAME) test

norm :
	clear
	#------- only [*.c] and [*.h] -------#
	@norminette *.c *.h

clean :
	@rm -f $(OBJET)

fclean : clean
	@rm -f $(NAME)
	@rm -f $(EXE)
	@rm -f $(LIB)

re : fclean all
