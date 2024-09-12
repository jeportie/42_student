# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeportie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/12 14:15:40 by jeportie          #+#    #+#              #
#    Updated: 2024/09/12 15:45:16 by jeportie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME = philo

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -pthread -v

# Directories
SRC_DIR = .
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

# Default rule
all: $(NAME)

# Compilation rule for the main program
$(NAME): $(OBJ)
	@echo "Compiling..."
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) > compile.log 2>&1
	@echo "Log file created. Running progress.sh..."
	@./progress.sh $(TOTAL_STEPS) compile.log
	@echo "Progress bar completed."
	@echo "Compilation complete."

# Rule to create the object directory
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Rule for compiling object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ 2>> compile.log

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

# Recompile everything
re: fclean all

.PHONY: all clean fclean re val san

