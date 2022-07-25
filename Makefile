# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 13:20:07 by aestraic          #+#    #+#              #
#    Updated: 2022/07/25 10:39:48 by aestraic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAIN = main.c
SRC =  get_next_line_utils.c get_next_line.c

COMPILED_MAIN = $(MAIN:.c=.out)
COMPILED_SRC = $(SRC:.c=.o)

EXE = $(COMPILED_MAIN)
OBJ  = $(COMPILED_SRC)

HEADER_PATH = header
LIB_PATH = lib
SRC_PATH = src
OBJ_PATH = obj

all:  obj exec

obj: $(OBJ)
%.o : %.c 
	gcc -Wall -Wextra -Werror -I$(HEADER_PATH) -c $^ 

exec: $(EXE)
%.out : %.c 	
	gcc -Wall -Wextra -Werror -I$(HEADER_PATH) $(COMPILED_SRC) $^ -o $@

# exec: $(EXE)
# %.out : %.c 	
# 	cc -Wall -Wextra -Werror -fsanitize=address -g -I$(HEADER_PATH) -L$(LIB_PATH) -lft $(COMPILED_SRC) $^ -o $@


val: library
	gcc -Wall -Wextra -Werror -I$(HEADER_PATH) -c main.c $(SRC) 
	gcc -Wall -Wextra -Werror -I$(HEADER_PATH) $(COMPILED_SRC) main.o -o $(COMPILED_MAIN)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(COMPILED_MAIN)

move:
	@mv $(OBJ)$^ $(OBJ_PATH)
	@echo Moved Objectfiles into /$(OBJ_PATH)

clean:
	@rm -f $(OBJ)
	@echo Objectfiles removed

fclean: clean
	@rm -f $(EXE)
	@echo Libraries and exeutables removed
	
re: fclean all
	@echo REDONE

.PHONY: clean fclean re obj exec library