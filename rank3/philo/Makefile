# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeportie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/12 14:15:40 by jeportie          #+#    #+#              #
#    Updated: 2024/09/13 14:07:55 by jeportie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# Colors
RESET   = \033[0m
GREEN   = \033[32m
BLUE    = \033[34m
YELLOW  = \033[33m
RED     = \033[31m
BOLD    = \033[1m

NAME = philo

CC = 		cc
CFLAGS = 	-Wall -Wextra -Werror -g3 -pthread -fPIC -v
SANITIZE = 	-fsanitize=thread
DEPFLAGS =  -MMD -MP

SRC_DIR = 	src
OBJ_DIR = 	obj
DEP_DIR =   obj/deps

SRC_MAIN =	main.c
SRC = 		$(addprefix src/, philo.c forks.c forks_2.c safe_init.c\
	  		init.c init_2.c monitor.c parsing.c routine.c simulation.c \
	 	 	printing.c utilities.c utilities_2.c utilities_3.c 42ft.c)
ALL_SRC =	$(SRC_MAIN) $(SRC)

OBJ = 		$(ALL_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEPS = 		$(OBJ:.o=.d)

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

run:
	@./philo $(filter-out $@,$(MAKECMDGOALS))

helgrind:
	@valgrind --tool=helgrind --history-level=full ./philo $(filter-out $@,$(MAKECMDGOALS))

valgrind:
	@valgrind --leak-check=full --track-origins=yes ./philo $(filter-out $@,$(MAKECMDGOALS))

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

	-include $(DEPS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@ 2>> .compile.log


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

help:
	@echo "$(BOLD)$(YELLOW)------------------- Philosopher project Makefile (42 school) -------------------$(RESET)"
	@echo ""
	@echo "$(BOLD)$(BLUE)Usage:$(RESET)"
	@echo "  make> [target]"
	@echo ""
	@echo "$(BOLD)$(BLUE)Available targets (++ = takes args after target):$(RESET)"
	@echo "$(GREEN)  make           $(RESET)- Download and enter in the make prompt."
	@echo "$(GREEN)  norm           $(RESET)- Runs norminette on the source files."
	@echo "$(GREEN)  all            $(RESET)- Compiles the philo project."
	@echo "$(GREEN)  san            $(RESET)- Compiles with thread sanitizer enabled. $(RED)!DO NOT USE VALGRIND.$(RESET)"
	@echo "$(GREEN)  run ++         $(RESET)- Executes the compiled philo program with optional arguments."
	@echo "$(GREEN)  helgrind ++    $(RESET)- Runs Valgrind's Helgrind tool for thread debugging."
	@echo "$(GREEN)  valgrind ++    $(RESET)- Runs Valgrind's leak-check for memory leaks debugging."
	@echo "$(GREEN)  clean          $(RESET)- Removes object files."
	@echo "$(GREEN)  fclean         $(RESET)- Removes object files and the executable."
	@echo "$(GREEN)  fullclean      $(RESET)- Removes the interface, object files, and executable."
	@echo "$(GREEN)  re             $(RESET)- Cleans and recompiles the project."
	@echo "$(GREEN)  help           $(RESET)- Displays this help message."
	@echo "$(GREEN)  run-prompt     $(RESET)- Starts a custom Make prompt interface."
	@echo ""
	@echo "$(BOLD)$(YELLOW)--------------------------------------------------------------------------$(RESET)"
# Catch-all rule to prevent errors with undefined targets
%:
	@:

.PHONY: all clean fclean re val san download-script run-prompt run norm valgrind helgrind
