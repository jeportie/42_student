# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeportie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/12 14:15:40 by jeportie          #+#    #+#              #
#    Updated: 2024/09/13 11:20:03 by jeportie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = 		cc
CFLAGS = 	-Wall -Wextra -Werror -g3 -pthread -v
SANITIZE = 	-fsanitize=thread
VALGRIND = 	-fPIC

SRC_DIR = 	src
OBJ_DIR = 	obj

SRC_MAIN =	main.c
SRC = 		$(addprefix src/, philo.c forks.c forks_2.c \
	  		init.c init_2.c monitor.c parsing.c routine.c simulation.c \
	 	 	printing.c utilities.c utilities_2.c utilities_3.c 42ft.c)
ALL_SRC =	$(SRC_MAIN) $(SRC)

OBJ = 		$(ALL_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Number of steps for progress bar (number of .o files)
TOTAL_STEPS := $(words $(OBJ))

# Script URL
SCRIPT_URL = https://github.com/jeromeDev94/make_interface.git

# Default target (run-prompt is first, so it runs by default)
run-prompt: download-script
	@./make_interface/make_prompt

download-script:
	@if [ ! -f make_interface/make_prompt ]; then \
		echo "Downloading script..."; \
		git clone $(SCRIPT_URL) > .download.log 2>&1;\
		./make_interface/progress 10 .download.log; \
		chmod +x make_interface/make_prompt; \
	fi

# 'run' target now captures arguments passed after 'run'
run:
	@./philo $(filter-out $@,$(MAKECMDGOALS))

norm:
	@norminette include/ main.c src/

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling..."
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) > .compile.log 2>&1
	@./make_interface/progress $(TOTAL_STEPS) .compile.log
	@echo "Compilation complete."

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ 2>> .compile.log

val: CFLAGS += $(VALGRIND)
val: re

# Thread sanitizer rule
san: CFLAGS += $(SANITIZE)
san: re

# Clean object files
clean:
	@echo "Cleaning object files"
	@rm -rf $(OBJ_DIR)

# Full clean (objects and executable)
fclean: clean
	@echo "Cleaning $(NAME)"
	@rm -f $(NAME)

fullclean: fclean
	@echo "Cleaning Interface"
	@rm -rf make_interface .download.log .compile.log

# Recompile everything
re: fclean all

# Catch-all rule to prevent errors with undefined targets
%:
	@:

.PHONY: all clean fclean re val san download-script run-prompt run
