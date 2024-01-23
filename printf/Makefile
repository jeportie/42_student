# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 19:12:55 by jeportie          #+#    #+#              #
#    Updated: 2024/01/23 16:21:15 by jeportie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./include
TEST_FLAGS = -w -I./include
OBJ_DIR = obj
OUTPUT_DIR = outputs
EXEC_DIR = exec

SRC = $(addprefix src/, ft_apply_precision.c ft_handle_char.c ft_handle_pointer.c ft_nbr_len.c \
      ft_utoa_base.c ft_apply_width.c ft_handle_hash_flag.c \
      ft_handle_space_flag.c ft_parse_flags.c ft_buffer_add.c \
      ft_handle_hexadecimal.c ft_handle_string.c ft_parse_format.c \
      ft_printf_globals.c ft_buffer_flush.c ft_handle_int.c ft_isconvert_spec.c \
      ft_printf.c ft_check_format.c ft_handle_plus_flag.c ft_isflag.c \
      ft_ulltoa_base.c)

LIBFT_SRC = $(addprefix libft/, ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
            ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
            ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
            ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \
            ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
            ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
            ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
            ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
            ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
            ft_toupper.c)

OBJ_SRC = $(SRC:src/%.c=$(OBJ_DIR)/%.o)
OBJ_LIBFT = $(LIBFT_SRC:libft/%.c=$(OBJ_DIR)/%.o)
OBJ = $(OBJ_SRC) $(OBJ_LIBFT)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)


$(OBJ_DIR)/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: libft/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: re

test: $(NAME) $(OBJ_DIR)/main.o
	mkdir -p $(EXEC_DIR)
	$(CC) $(TEST_FLAGS) -o $(EXEC_DIR)/test_program $(OBJ_DIR)/main.o $(NAME)
	./$(EXEC_DIR)/test_program

$(OBJ_DIR)/main.o: tests/main.c
	$(CC) $(TEST_FLAGS) -c tests/main.c -o $(OBJ_DIR)/main.o

tclean: fclean
	rm -rf $(EXEC_DIR)

test_ft_printf: $(NAME) $(OBJ_DIR)/main_ft_printf.o
	mkdir -p $(EXEC_DIR)
	$(CC) $(TEST_FLAGS) -o $(EXEC_DIR)/test_ft_printf $(OBJ_DIR)/main_ft_printf.o $(NAME)

$(OBJ_DIR)/main_ft_printf.o: tests/main_ft_printf.c
	$(CC) $(TEST_FLAGS) -c tests/main_ft_printf.c -o $(OBJ_DIR)/main_ft_printf.o

test_printf: $(NAME) $(OBJ_DIR)/main_printf.o
	$(CC) $(TEST_FLAGS) -o $(EXEC_DIR)/test_printf $(OBJ_DIR)/main_printf.o $(NAME)

$(OBJ_DIR)/main_printf.o: tests/main_printf.c
	$(CC) $(TEST_FLAGS) -c tests/main_printf.c -o $(OBJ_DIR)/main_printf.o

difftest: test_ft_printf test_printf
	mkdir -p $(OUTPUT_DIR)
	./$(EXEC_DIR)/test_ft_printf > $(OUTPUT_DIR)/output_ft_printf.txt
	./$(EXEC_DIR)/test_printf > $(OUTPUT_DIR)/output_printf.txt
	clear
	diff -u $(OUTPUT_DIR)/output_printf.txt $(OUTPUT_DIR)/output_ft_printf.txt

dclean: fclean
	rm -f main_ft_printf.o main_printf.o
	rm -rf $(OUTPUT_DIR) $(EXEC_DIR)

.PHONY: all clean fclean re bonus test tclean test_ft_printf test_printf difftest dclean
