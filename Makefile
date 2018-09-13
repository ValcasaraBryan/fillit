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

SRC = ft_putchar.c ft_putstr.c ft_strcmp.c ft_strdup.c\
	ft_strlen.c get_next_piece.c library_generator.c parsing.c\
	smallest_square.c tab_creator.c tetricmp.c tetridetector.c\
	database_creation.c recursive.c place_piece.c main.c

OBJET = $(SRC:.c=.o)

HEAD = -I fillit.h

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
