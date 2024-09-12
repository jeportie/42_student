# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeportie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/12 14:15:40 by jeportie          #+#    #+#              #
#    Updated: 2024/09/12 22:16:13 by jeportie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME = philo

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -pthread -v

# Directories
SRC_DIR = src
OBJ_DIR = obj

# Source files
SRC_MAIN = $(SRC_DIR)/main.c
SRC = $(SRC_DIR)/philo.c $(SRC_DIR)/forks.c $(SRC_DIR)/forks_2.c \
	  $(SRC_DIR)/init.c $(SRC_DIR)/init_2.c $(SRC_DIR)/monitor.c \
	  $(SRC_DIR)/parsing.c $(SRC_DIR)/routine.c $(SRC_DIR)/simulation.c \
	  $(SRC_DIR)/printing.c $(SRC_DIR)/utilities.c $(SRC_DIR)/utilities_2.c \
	  $(SRC_DIR)/utilities_3.c $(SRC_DIR)/42ft.c

# All sources (main + others)
ALL_SRC = $(SRC_MAIN) $(SRC)

# Object files
OBJ = $(ALL_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Sanitize and Valgrind flags
SANITIZE = -fsanitize=thread
VALGRIND = -fPIC

# Number of steps for progress bar (number of .o files)
TOTAL_STEPS := $(words $(OBJ))

# Script URL
SCRIPT_URL = https://github.com/jeromeDev94/make_interface.git

# Default target (run-prompt is first, so it runs by default)
run-prompt: download-script
	./make_interface/make_prompt.sh

# Target to download and make the script executable (only if not exists)
download-script:
	@if [ ! -f make_prompt.sh ]; then \
		echo "Downloading script..."; \
		git clone $(SCRIPT_URL) > .download.log 2>&1;\
		./progress 10 .download.log; \
		chmod +x make_interface/make_prompt.sh; \
	fi

run:
	@./philo 5 800 200 200 7

# Compilation rule for the main program
all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling..."
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) > .compile.log 2>&1
	@./progress $(TOTAL_STEPS) .compile.log
	@echo "\nCompilation complete."

# Rule to create the object directory
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Rule for compiling object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ 2>> .compile.log

# Valgrind rule
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

.PHONY: all clean fclean re val san download-script run-prompt

