# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 03:01:03 by jeportie          #+#    #+#              #
#    Updated: 2023/12/09 15:17:16 by jeportie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libfmanip.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I libft_project_Nov23/libft

SRC = ft_count_flines.c ft_fclose.c ft_filesize.c ft_flines_to_str.c \
      ft_fopen.c ft_fread.c ft_free_memory.c ft_free_node.c \
      ft_load_tests.c ft_parse_line_to_test.c ft_print_testlst.c \
      ft_testlst_add_back.c ft_testlst_clear.c ft_testlst_delone.c \
      ft_testlst_new.c ft_testfile_option_format.c ft_test_function.c \
	  ft_call.c ft_call_and_exec_cft.c libfmanip_globals.c

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
