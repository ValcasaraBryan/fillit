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

EXE = fillit

SRC = ft_putchar.c ft_putstr.c ft_strcmp.c ft_strdup.c\
	ft_strlen.c get_next_piece.c library_generator.c parsing.c\
	smallest_square.c tab_creator.c tetricmp.c tetridetector.c\
	database_creation.c recursive.c place_piece.c

OBJET = $(SRC:.c=.o)

HEAD = -I fillit.h

FLAG = -Wall -Wextra -Werror

all : lib $(NAME) comp

$(NAME) : $(OBJET)
	@ar rc $@ $^
	@ranlib $@

lib : 
	@make -C ../libft

%.o:%.c %.h
	@clang -o $@ -c $<

comp : main.c
	@clang $(NAME) ../libft/libft.a main.c -o $(EXE)
exe : all comp
		#time ./$(EXE) ../Testeurs/42FileChecker/fillit_checker/correct_file/valid_0
	#./$(EXE) ../../../Testeurs/42FileChecker/fillit_checker/error_file/error_0
	#./$(EXE) ../../../Testeurs/42FileChecker/fillit_checker/correct_file/valid_1
	#./$(EXE) ../../../Testeurs/42FileChecker/fillit_checker/error_file/error_1
	#./$(EXE) ../../../Testeurs/42FileChecker/fillit_checker/correct_file/valid_2
	#./$(EXE) ../../../Testeurs/42FileChecker/fillit_checker/error_file/error_2
	#./$(EXE) ../../../Testeurs/42FileChecker/fillit_checker/correct_file/valid_3
	#./$(EXE) ../../../Testeurs/42FileChecker/fillit_checker/error_file/error_3
	#./$(EXE) ../../../Testeurs/42FileChecker/fillit_checker/correct_file/valid_4
	#./$(EXE) ../../../Testeurs/42FileChecker/fillit_checker/error_file/error_4
	#./$(EXE) ../../../Testeurs/42FileChecker/fillit_checker/correct_file/valid_5
	#./$(EXE) ../../../Testeurs/42FileChecker/fillit_checker/error_file/error_5
	#./$(EXE) ../../../Testeurs/42FileChecker/fillit_checker/correct_file/valid_6
	#./$(EXE) ../../../Testeurs/42FileChecker/fillit_checker/error_file/error_6
			#time ./$(EXE) ../Testeurs/42FileChecker/fillit_checker/correct_file/valid_7
	#./$(EXE) ../../../Testeurs/42FileChecker/fillit_checker/error_file/error_7
	#./$(EXE) ../../../Testeurs/42FileChecker/fillit_checker/correct_file/valid_8
	#./$(EXE) ../../../Testeurs/42FileChecker/fillit_checker/error_file/error_8
		#./$(EXE) ../Testeurs/42FileChecker/fillit_checker/correct_file/valid_9
	#./$(EXE) ../../../Testeurs/42FileChecker/fillit_checker/error_file/error_9
	#./$(EXE) ../../../Testeurs/42FileChecker/fillit_checker/correct_file/valid_10
	#./$(EXE) ../../../Testeurs/42FileChecker/fillit_checker/error_file/error_10
		#time ./$(EXE) ../Testeurs/42FileChecker/fillit_checker/correct_file/valid_11
	#./$(EXE) ../../../Testeurs/42FileChecker/fillit_checker/error_file/error_11
	#./$(EXE) ../../../Testeurs/42FileChecker/fillit_checker/correct_file/valid_12
	#./$(EXE) ../../../Testeurs/42FileChecker/fillit_checker/error_file/error_12
	#./$(EXE) ../../../Testeurs/42FileChecker/fillit_checker/correct_file/valid_13
	#./$(EXE) ../../../Testeurs/42FileChecker/fillit_checker/error_file/error_13
	#./$(EXE) ../../../Testeurs/42FileChecker/fillit_checker/correct_file/valid_14
	#./$(EXE) ../../../Testeurs/42FileChecker/fillit_checker/error_file/error_14
	#./$(EXE) ../../../Testeurs/42FileChecker/fillit_checker/correct_file/valid_15
	#./$(EXE) ../../../Testeurs/42FileChecker/fillit_checker/error_file/error_15
	#./$(EXE) ../../../Testeurs/42FileChecker/fillit_checker/correct_file/valid_16
	#./$(EXE) ../../../Testeurs/42FileChecker/fillit_checker/error_file/error_16
	#./$(EXE) ../../../Testeurs/42FileChecker/fillit_checker/correct_file/valid_17
	#./$(EXE) ../../../Testeurs/42FileChecker/fillit_checker/error_file/error_17
	#./$(EXE) ../../../Testeurs/42FileChecker/fillit_checker/correct_file/valid_18
	#./$(EXE) ../../../Testeurs/42FileChecker/fillit_checker/error_file/error_18
		#time ./$(EXE) ../Testeurs/42FileChecker/fillit_checker/correct_file/valid_19
	#./$(EXE) ../../../Testeurs/42FileChecker/fillit_checker/error_file/error_19
	#./$(EXE) ../../../Testeurs/42FileChecker/fillit_checker/correct_file/valid_20
	#./$(EXE) ../../../Testeurs/42FileChecker/fillit_checker/error_file/error_20
	#./$(EXE) ../../../Testeurs/42FileChecker/fillit_checker/correct_file/valid_21
	#./$(EXE) ../../../Testeurs/42FileChecker/fillit_checker/error_file/error_21
	#./$(EXE) ../../../Testeurs/42FileChecker/fillit_checker/error_file/error_22
	#./$(EXE) ../../../Testeurs/42FileChecker/fillit_checker/error_file/error_23
	#./$(EXE) ../../../Testeurs/42FileChecker/fillit_checker/error_file/error_24
	#./$(EXE) ../../../Testeurs/42FileChecker/fillit_checker/error_file/error_25
	./$(EXE) testeur
debug : main.c
	cpp main.c

clean :
	@rm -f $(OBJET)

fclean : clean
	@rm -f $(NAME)
	@rm -f $(EXE)
re : fclean all
