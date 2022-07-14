# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aestraic <aestraic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 13:20:07 by aestraic          #+#    #+#              #
#    Updated: 2022/07/13 16:22:22 by aestraic         ###   ########.fr        #
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

all:  library obj exec

obj: $(OBJ)
%.o : %.c 
	cc -Wall -Wextra -Werror -I$(HEADER_PATH) -c $^ 

exec: $(EXE)
%.out : %.c 	
	cc -Wall -Wextra -Werror -I$(HEADER_PATH) -L$(LIB_PATH) -lft $(COMPILED_SRC) $^ -o $@

library:
#	@echo MAKE LIBFT
	@make all -C	$(SRC_PATH)/libft
	
#	@echo MAKE PRINTF
	@make all -C	$(SRC_PATH)/ft_printf

val: library
	gcc -Wall -Wextra -Werror -I$(HEADER_PATH) -c $(SRC) main.c
	gcc -Wall -Wextra -Werror -I$(HEADER_PATH) $(COMPILED_SRC) main.o -L$(LIB_PATH) -lft -o $(COMPILED_MAIN)
	valgrind --leak-check=full --show-leak-kinds=all ./$(COMPILED_MAIN)

move:
	@make move -C	$(SRC_PATH)/libft
	@make move -C	$(SRC_PATH)/ft_printf
	@mv $(OBJ)$^ $(OBJ_PATH)
	@echo Moved Objectfiles into /$(OBJ_PATH)

clean:
	@make clean -C $(SRC_PATH)/libft
	@make clean -C $(SRC_PATH)/ft_printf
	@rm -f $(OBJ)
	@echo Objectfiles removed

fclean: clean
	@make fclean -C $(SRC_PATH)/libft
	@make fclean -C $(SRC_PATH)/ft_printf
	@rm -f $(EXE)
	@echo Libraries and exeutables removed
	
re: fclean all
	@echo REDONE

.PHONY: clean fclean re obj exec library