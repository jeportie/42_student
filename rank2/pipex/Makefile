# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 19:12:55 by jeportie          #+#    #+#              #
#    Updated: 2024/07/16 13:19:17 by jeportie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 			pipex.a
CC = 			cc
CFLAGS = 		-Wall -Wextra -g3 -Iinclude -Ilibft
OBJ_DIR = 		obj
OUTPUT_DIR = 	outputs
EXEC_DIR = 		exec
VALGRIND = 		valgrind --track-origins=yes --leak-check=full #--track-fds=yes \
				#--trace-children=yes
LIBFT_DIR = 	libft
LIBS = 			-L$(LIBFT_DIR) -lft

INIT = 		$(addprefix src/init_src/, ft_init_pipex.c \
			 ft_here_doc_mode.c ft_parse_cmd.c)
EXEC = 		$(addprefix src/exec_src/, ft_fork_and_exec.c ft_process.c)

OBJ_INIT	  =	$(INIT:src/init_src/%.c=$(OBJ_DIR)/init_src_%.o)
OBJ_EXEC	  =	$(EXEC:src/exec_src/%.c=$(OBJ_DIR)/exec_src_%.o)
OBJ =			$(OBJ_INIT) $(OBJ_EXEC)

all: $(LIBFT_DIR)/libft.a $(NAME)

$(LIBFT_DIR)/libft.a:
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ_DIR) $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/init_src_%.o: src/init_src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/exec_src_%.o: src/exec_src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

eclean: fclean
	rm -rf $(EXEC_DIR)
	rm -f $(LOG)

re: fclean all

main: all $(OBJ_DIR)/main.o
	mkdir -p $(EXEC_DIR)
	$(CC) $(CFLAGS) -o $(EXEC_DIR)/pipex $(OBJ_DIR)/main.o $(NAME) $(LIBS)

run: all $(OBJ_DIR)/main.o
	mkdir -p $(EXEC_DIR)
	$(CC) $(CFLAGS) -o $(EXEC_DIR)/pipex $(OBJ_DIR)/main.o $(NAME) $(LIBS); \
	./$(EXEC_DIR)/pipex Makefile "ls -l" "wc -l" outfile

debug: all $(OBJ_DIR)/main.o
	mkdir -p $(EXEC_DIR)
	$(CC) $(CFLAGS) -o $(EXEC_DIR)/pipex $(OBJ_DIR)/main.o $(NAME) $(LIBS); \
	$(VALGRIND) ./$(EXEC_DIR)/pipex Makefile "ls -l" "grep 0" "wc -l" outfile

heredoc: all $(OBJ_DIR)/main.o
	mkdir -p $(EXEC_DIR)
	$(CC) $(CFLAGS) -o $(EXEC_DIR)/pipex $(OBJ_DIR)/main.o $(NAME) $(LIBS); \
	$(VALGRIND) ./$(EXEC_DIR)/pipex here_doc EOF "cat -e" "grep Hello" outfile

lldb: all $(OBJ_DIR)/main.o
	mkdir -p $(EXEC_DIR)
	$(CC) $(CFLAGS) -o $(EXEC_DIR)/pipex $(OBJ_DIR)/main.o $(NAME) $(LIBS); \
	read -p "Enter arguments: " ARGS; \
	lldb -- ./$(EXEC_DIR)/pipex $$ARGS

$(OBJ_DIR)/main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o $@

.PHONY: all clean fclean re main eclean
