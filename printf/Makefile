# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 19:12:55 by jeportie          #+#    #+#              #
#    Updated: 2024/01/12 22:33:57 by jeportie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.function_library/libft

SRC = ft_apply_precision.c ft_handle_char.c ft_handle_pointer.c ft_nbr_len.c \
	  ft_utoa_base.c ft_apply_width.c ft_handle_hash_flag.c \
	  ft_handle_space_flag.c ft_parse_flags.c ft_buffer_add.c \
	  ft_handle_hexadecimal.c ft_handle_string.c ft_parse_format.c \
	  printf_globals.c ft_buffer_flush.c ft_handle_int.c ft_isconvert_spec.c \
	  ft_printf.c ft_check_format.c ft_handle_plus_flag.c ft_isflag.c \
	  ft_ulltoa_base.c

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
