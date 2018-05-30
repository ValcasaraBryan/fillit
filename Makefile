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

SRC = ft_putchar.c ft_putstr.c ft_strcmp.c ft_strdup.c\
	ft_strlen.c get_next_piece.c library_generator.c parsing.c\
	smallest_square.c tab_creator.c tetricmp.c tetridetector.c\
	database_creation.c recursive.c place_piece.c

OBJET = $(SRC:.c=.o)

HEAD = -I fillit.h

FLAG = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJET)
	@clang $(SRC) main.c -o $(NAME)

exe :
	time ./$(NAME) valid_test1
	time ./$(NAME) valid_19

clean :
	@rm -f $(OBJET)

fclean : clean
	@rm -f $(NAME)
	@rm -f $(EXE)
re : fclean all
