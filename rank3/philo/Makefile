# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeportie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/12 14:15:40 by jeportie          #+#    #+#              #
#    Updated: 2024/09/14 18:54:05 by jeportie         ###   ########.fr        #
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

SRC = 		$(addprefix src/, philo.c forks.c forks_2.c safe_init.c \
	  		init.c init_2.c monitor.c parsing.c routine.c simulation.c \
	 	 	printing.c utilities.c utilities_2.c utilities_3.c 42ft.c)

# Object files excluding main.c
OBJ = 		$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
# Dependency files excluding main.c
DEPS = 		$(OBJ:.o=.d)

# Number of steps for progress bar (number of .o files)
TOTAL_STEPS := $(words $(OBJ))

# Script URL
SCRIPT_URL = https://github.com/jeromeDev94/make_interface.git

# Default target (run-prompt is first, so it runs by default)
run-prompt: download-script
	@./make_interface/make_prompt

download-script:
	@if [ ! -d make_interface ]; then \
		echo "Downloading script..."; \
		git clone $(SCRIPT_URL) > .download.log 2>&1;\
		./make_interface/progress 10 .download.log; \
		chmod +x make_interface/make_prompt; \
		echo "Script downloaded !"; \
		make -s help; \
	fi

run:
	@./philo $(filter-out $@,$(MAKECMDGOALS))

helgrind:
	@valgrind --tool=helgrind --history-level=full ./philo $(filter-out $@,$(MAKECMDGOALS))

valgrind:
	@valgrind --leak-check=full --track-origins=yes ./philo $(filter-out $@,$(MAKECMDGOALS))

norm:
	@norminette include/ main.c src/

todo:
	@vim .philo.todo.md

create-cal:
	@if [ ! -d .calendar ]; then \
		mkdir -p .calendar; \
		touch ./.calendar/$(NAME).calendar; \
	fi

calendar: create-cal
	vim -c "let g:calendar_cache_directory=expand('./.calendar/')"  -c ":Calendar" .calendar/$(NAME).calendar -c ":bd .calendar/philo.calendar" 

uml:
	@./make_interface/interactive_select 

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_DIR)/main.o
	echo "Compiling..."
	$(CC) $(CFLAGS) $(OBJ) $(OBJ_DIR)/main.o -o $(NAME) > .compile.log 2>&1
	./make_interface/progress $(TOTAL_STEPS) .compile.log
	echo "Compilation complete."

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Generate object files and corresponding .d files for SRC
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@ 2>> .compile.log

# Handle main.c separately
$(OBJ_DIR)/main.o: main.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ 2>> .compile.log

# Include dependency files after object files are generated
-include $(DEPS)

# Thread sanitizer rule
san: CFLAGS += $(SANITIZE)
san: CC = clang
san: re

# Thread sanitizer rule
default: CFLAGS -= $(SANITIZE)
default: CC = cc
default: re

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
	@echo "Welcome to the 42 School Make Interface - 42MI"
	@echo ""
	@echo "$(BOLD)$(BLUE)Usage:$(RESET)"
	@echo "  Make> [target]"
	@echo ""
	@echo "$(BOLD)$(BLUE)Available targets (++ = takes args after target):$(RESET)"
	@echo "$(GREEN)  norm           $(RESET)- Runs norminette on the source files."
	@echo "$(GREEN)  all            $(RESET)- Compiles the philo project."
	@echo "$(GREEN)  san            $(RESET)- Clang compiles with thread sanitizer enabled. $(RED)!DO NOT USE VALGRIND.$(RESET)"
	@echo "$(GREEN)  default        $(RESET)- Unable sanitizer thread and compiles with cc (Valgrind OK)"
	@echo "$(GREEN)  run ++         $(RESET)- Executes the compiled philo program with optional arguments."
	@echo "$(GREEN)  helgrind ++    $(RESET)- Runs Valgrind's Helgrind tool for thread debugging."
	@echo "$(GREEN)  valgrind ++    $(RESET)- Runs Valgrind's leak-check for memory leaks debugging."
	@echo "$(GREEN)  clean          $(RESET)- Removes object files."
	@echo "$(GREEN)  fclean         $(RESET)- Removes object files and the executable."
	@echo "$(GREEN)  fullclean      $(RESET)- Removes the interface, object files, and executable."
	@echo "$(GREEN)  re             $(RESET)- Cleans and recompiles the project."
	@echo "$(GREEN)  uml            $(RESET)- Enter in the UML schematics menu of the projects."
	@echo "$(GREEN)  calendar       $(RESET)- Displays the project calendar."
	@echo "$(GREEN)  todo           $(RESET)- Displays the project todo list."
	@echo "$(GREEN)  run-prompt     $(RESET)- Starts a custom Make prompt interface."
	@echo "$(GREEN)  help           $(RESET)- Displays this help message."
	@echo ""
	@echo "$(BOLD)$(YELLOW)-------------------------------------------------------------------------------$(RESET)"
# Catch-all rule to prevent errors with undefined targets
%:
	@:

.PHONY: all clean fclean re val san download-script run-prompt run norm valgrind helgrind
