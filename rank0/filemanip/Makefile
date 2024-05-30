# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 03:01:03 by jeportie          #+#    #+#              #
#    Updated: 2023/12/27 14:48:25 by jeportie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libfmanip.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I libft_project_Nov23/libft

SRC = ft_count_flines.c ft_fclose.c ft_filesize.c ft_flines_to_str.c \
      ft_fopen.c ft_fread.c ft_strtoupper.c
	
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
