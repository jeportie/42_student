# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 19:12:55 by jeportie          #+#    #+#              #
#    Updated: 2024/07/05 10:18:38 by jeportie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 			pipex.a
CC = 			cc
CFLAGS = 		-Wall -Wextra -g3 -Iinclude -Ilibft
OBJ_DIR = 		obj
OUTPUT_DIR = 	outputs
EXEC_DIR = 		exec
VALGRIND = 		valgrind --track-origins=yes --leak-check=full
LIBFT_DIR = 	libft
LIBS = 			-L$(LIBFT_DIR) -lft

UTILITIES = 	$(addprefix src/utilities_src/, ft_exit_failure.c)

OBJ_UTILITIES =	$(UTILITIES:src/utilities_src/%.c=$(OBJ_DIR)/utilities_src_%.o)
OBJ =			$(OBJ_UTILITIES) $(OBJ_GARBAGE)

all: $(LIBFT_DIR)/libft.a $(NAME)

$(LIBFT_DIR)/libft.a:
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ_DIR) $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/utilities_src_%.o: src/utilities_src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

eclean: fclean
	rm -rf $(EXEC_DIR)

re: fclean all

main: all $(OBJ_DIR)/main.o
	mkdir -p $(EXEC_DIR)
	$(CC) $(CFLAGS) -o $(EXEC_DIR)/pipex $(OBJ_DIR)/main.o $(NAME) $(LIBS)

run: all $(OBJ_DIR)/main.o
	mkdir -p $(EXEC_DIR)
	$(CC) $(CFLAGS) -o $(EXEC_DIR)/pipex $(OBJ_DIR)/main.o $(NAME) $(LIBS); \
	./$(EXEC_DIR)/pipex

debug: all $(OBJ_DIR)/main.o
	mkdir -p $(EXEC_DIR)
	$(CC) $(CFLAGS) -o $(EXEC_DIR)/pipex $(OBJ_DIR)/main.o $(NAME) $(LIBS); \
	$(VALGRIND) ./$(EXEC_DIR)/pipex 

lldb: all $(OBJ_DIR)/main.o
	mkdir -p $(EXEC_DIR)
	$(CC) $(CFLAGS) -o $(EXEC_DIR)/pipex $(OBJ_DIR)/main.o $(NAME) $(LIBS); \
	lldb $(EXEC_DIR)/pipex

$(OBJ_DIR)/main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o $@

.PHONY: all clean fclean re main eclean
