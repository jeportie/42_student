# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 03:01:03 by jeportie          #+#    #+#              #
#    Updated: 2023/12/27 18:31:09 by jeportie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libfmanip.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I libft_project_Nov23/libft

SRC = ft_free_memory.c ft_free_node.c ft_call_func_int.c ft_call_func_size_t.c\
      ft_load_tests.c ft_parse_line_to_test.c ft_testlst_add_back.c\
	  ft_testlst_clear.c ft_testlst_delone.c ft_call_func_str.c\
      ft_testlst_new.c ft_testfile_option_format.c ft_test_function.c \
	  ft_call.c ft_call_and_exec_cft.c libfmanip_globals.c\
	  ft_find_ftparam_type.c ft_segfault_check.c ft_run_test.c\
	  ft_char_test_functions.c ft_strtester.c ft_sizettest_for_ssz.c \
	  ft_sizettest_for_str.c ft_sizettester_ssz.c ft_sizettester_str.c\
	  ft_chartest_for_si.c ft_chartest_for_ssz.c ft_chartest_for_str.c\
	  ft_find_ftreturn_type.c ft_inttester_int.c ft_inttester_str.c\
	  ft_inttester_vvz.c ft_inttester_ssz.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
