# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 03:01:03 by jeportie          #+#    #+#              #
#    Updated: 2023/12/28 14:52:12 by jeportie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftest.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I ../lib -L../lib -lft -lfmanip -lbsd

SRC = ft_call_and_exec_cft.c ft_call_func_int.c ft_call_func_size_t.c \
	  ft_call_func_str.c ft_find_ftparam_type.c ft_find_ftreturn_type.c \
	  ft_free_memory.c ft_free_node.c ft_inttester_int.c ft_inttester_ssz.c \
	  ft_inttester_str.c ft_inttester_vvz.c ft_inttest_for_int.c \
	  ft_inttest_for_ssz.c ft_inttest_for_str.c ft_inttest_for_vvz.c \
	  ft_load_tests.c ft_parse_line_to_test.c ft_run_test.c \
	  ft_sizettester_ssz.c ft_sizettester_str.c ft_sizettest_for_ssz.c \
	  ft_sizettest_for_str.c ft_strtester_si.c ft_strtester_ssz.c \
	  ft_strtester_str.c ft_strtest_for_si.c ft_strtest_for_ssz.c \
	  ft_strtest_for_str.c ft_testfile_option_format.c ft_testlst_add_back.c \
	  ft_testlst_clear.c ft_testlst_delone.c ft_testlst_new.c \
	  libftest_globals.c

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

.PHONY: all clean fclean re<F4>
