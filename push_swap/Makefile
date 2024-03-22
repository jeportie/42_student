# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 19:12:55 by jeportie          #+#    #+#              #
#    Updated: 2024/03/22 18:20:40 by jeportie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./include
OBJ_DIR = obj
OUTPUT_DIR = outputs
EXEC_DIR = exec
VALGRIND = valgrind --track-origins=yes --leak-check=full

SRC =			$(addprefix src/, ft_init_stack.c ft_empty_stack.c a_rules.c \
				ab_rules.c b_rules.c ft_parse_arg.c radix_sort.c \
				ft_print_stack.c ft_push_to_stack.c ft_validate_inputs.c \
				ft_isinteger.c ft_argc_len.c ft_free_split.c) 

PRINTF_SRC =	$(addprefix ft_printf/, ft_apply_precision.c ft_handle_char.c \
			 	ft_handle_pointer.c ft_nbr_len.c ft_utoa_base.c ft_apply_width.c \
			 	ft_handle_hash_flag.c ft_handle_space_flag.c ft_parse_flags.c \
			 	ft_buffer_add.c ft_handle_hexadecimal.c ft_handle_string.c \
			 	ft_parse_format.c ft_printf_globals.c ft_buffer_flush.c \
			 	ft_handle_int.c ft_isconvert_spec.c ft_printf.c ft_check_format.c \
			 	ft_handle_plus_flag.c ft_isflag.c ft_ulltoa_base.c)

LIBFT_SRC = 	$(addprefix libft/, ft_atoi.c ft_atol.c ft_bzero.c ft_isalnum.c \
            	ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
            	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
            	ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \
            	ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
            	ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
            	ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
            	ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
            	ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
            	ft_toupper.c ft_calloc.c ft_realloc.c get_next_line.c)

OBJ_SRC =		$(SRC:src/%.c=$(OBJ_DIR)/%.o)
OBJ_PRINTF =	$(PRINTF_SRC:ft_printf/%.c=$(OBJ_DIR)/%.o)
OBJ_LIBFT =		$(LIBFT_SRC:libft/%.c=$(OBJ_DIR)/%.o)
OBJ =			$(OBJ_SRC) $(OBJ_PRINTF) $(OBJ_LIBFT)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)


$(OBJ_DIR)/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: ft_printf/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: libft/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all


main: all $(NAME) $(OBJ_DIR)/main.o
	mkdir -p $(EXEC_DIR)
	@echo -n "Enter some input (only digits and numbers)."; \
	read user_input; \
	$(CC) $(C_FLAGS) -o $(EXEC_DIR)/push_swap $(OBJ_DIR)/main.o $(NAME); \
	./$(EXEC_DIR)/push_swap $$user_input

debug: all $(NAME) $(OBJ_DIR)/main.o
	mkdir -p $(EXEC_DIR)
	@echo -n "Enter some input (only digits and numbers)."; \
	read user_input; \
	$(CC) $(C_FLAGS) -o $(EXEC_DIR)/push_swap $(OBJ_DIR)/main.o $(NAME); \
	$(VALGRIND) ./$(EXEC_DIR)/push_swap $$user_input

gnl: all $(NAME) $(OBJ_DIR)/gnlmain.o
	mkdir -p $(EXEC_DIR)
	$(CC) $(C_FLAGS) -o $(EXEC_DIR)/gnl_test $(OBJ_DIR)/gnlmain.o $(NAME)
	$(VALGRIND) ./$(EXEC_DIR)/gnl_test

$(OBJ_DIR)/main.o: main.c
	$(CC) $(C_FLAGS) -c main.c -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/gnlmain.o: tests/gnltest.c
	$(CC) $(C_FLAGS) -c tests/gnltest.c -o $(OBJ_DIR)/gnlmain.o

eclean: fclean
	rm -rf $(EXEC_DIR)

.PHONY: all clean fclean re main eclean
