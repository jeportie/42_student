# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeportie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 12:25:36 by jeportie          #+#    #+#              #
#    Updated: 2024/02/08 21:40:29 by jeportie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgnl.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I. -g3

SRC = get_next_line_utils.c get_next_line.c
OBJ = $(SRC:.c=.o)
BONUS = get_next_line_utils_bonus.c get_next_line_bonus.c
OBJB = $(BONUS:.c=.o)


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

main: fclean
	$(CC) $(CFLAGS) $(SRC) main.c -o my_prog
	valgrind --track-origins=yes --leak-check=full ./my_prog

bonus: fclean
	$(CC) $(CFLAGS) $(BONUS) main.c -o my_bonus_prog
	valgrind --track-origins=yes --leak-check=full ./my_bonus_prog

.PHONY: all clean fclean re
