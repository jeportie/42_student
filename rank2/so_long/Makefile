# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 19:12:55 by jeportie          #+#    #+#              #
#    Updated: 2024/06/07 00:02:24 by jeportie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 			so_long.a
CC = 			cc
CFLAGS = 		-Wall -Wextra -g3 -Iinclude -Ilibft
OBJ_DIR = 		obj
OUTPUT_DIR = 	outputs
EXEC_DIR = 		exec
VALGRIND = 		valgrind --track-origins=yes --leak-check=full
LIBS = 			-Llibft -lmlx -lXext -lX11 -lft -ldl -lglfw -pthread -lm

UTILITIES = 	$(addprefix src/utilities_src/, ft_exit_failure.c ft_display_controls.c\
					ft_flood_fill.c ft_free_game.c ft_free_map.c ft_generate_color.c)

MAP_PARSER =	$(addprefix src/map_parser_src/, ft_check_map.c ft_parse_map.c \
					ft_read_map.c ) 

MAP_RENDER = 	$(addprefix src/map_render_src/, ft_load_frame.c ft_put_tile.c \
					ft_render_map.c)

OBJ_UTILITIES =	$(UTILITIES:src/utilities_src/%.c=$(OBJ_DIR)/utilities_src_%.o)
OBJ_MAP_PARSE =	$(MAP_PARSER:src/map_parser_src/%.c=$(OBJ_DIR)/map_parser_src_%.o)
OBJ_MAP_REND  =	$(MAP_RENDER:src/map_render_src/%.c=$(OBJ_DIR)/map_render_src_%.o)
OBJ =			$(OBJ_MAP_PARSE) $(OBJ_MAP_REND) $(OBJ_UTILITIES)

all: libft/libft.a $(NAME)

libft/libft.a:
	make -C libft

$(NAME): $(OBJ_DIR) $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/utilities_src_%.o: src/utilities_src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/map_parser_src_%.o: src/map_parser_src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/map_render_src_%.o: src/map_render_src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

eclean: fclean
	rm -rf $(EXEC_DIR)

re: fclean all

main: all $(NAME) $(OBJ_DIR)/main.o
	mkdir $(EXEC_DIR)
	$(CC) $(CFLAGS) -o $(EXEC_DIR)/so_long $(OBJ_DIR)/main.o $(NAME) $(LIBS)

run: all $(NAME) $(OBJ_DIR)/main.o
	mkdir $(EXEC_DIR)
	$(CC) $(CFLAGS) -o $(EXEC_DIR)/so_long $(OBJ_DIR)/main.o $(NAME) $(LIBS); \
	./$(EXEC_DIR)/so_long "assets/maps/test_map.ber" | cat -e

debug: all $(NAME) $(OBJ_DIR)/main.o
	mkdir $(EXEC_DIR)
	$(CC) $(CFLAGS) -o $(EXEC_DIR)/so_long $(OBJ_DIR)/main.o $(NAME) $(LIBS); \
	$(VALGRIND) ./$(EXEC_DIR)/so_long "assets/maps/test_map.ber"
	
lldb: all $(NAME) $(OBJ_DIR)/main.o
	mkdir $(EXEC_DIR)
	$(CC) $(CFLAGS) -o $(EXEC_DIR)/so_long $(OBJ_DIR)/main.o $(NAME) $(LIBS); \
	lldb $(EXEC_DIR)/so_long

$(OBJ_DIR)/main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o $(OBJ_DIR)/main.o

.PHONY: all clean fclean re main eclean
