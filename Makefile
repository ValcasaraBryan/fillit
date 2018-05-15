# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/15 18:28:13 by brvalcas          #+#    #+#              #
#    Updated: 2018/05/15 18:28:15 by brvalcas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit.a

EXE = executable

SRC = initlist.c ft_get_next_piece.c tetridetector.c

OBJET = $(SRC:.c=.o)

HEAD = -I fillit.h

FLAG = -Wall -Wextra -Werror

all : lib $(NAME)

$(NAME) : $(OBJET)
	@ar rc $@ $^
	@ranlib $@

lib : 
	@make -C ../libft

%.o:%.c %.h
	@clang -o $@ -c $<

comp : all main.c
	@clang $(NAME) ../libft/libft.a main.c -o $(EXE)
exe : comp
	@./$(EXE) valide.exemple.fillit

debug : main.c
	cpp main.c

clean :
	@rm -f $(OBJET)

fclean : clean
	@rm -f $(NAME)
	@rm -f $(EXE)
re : fclean all
