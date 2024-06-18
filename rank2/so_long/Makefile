# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 19:12:55 by jeportie          #+#    #+#              #
#    Updated: 2024/06/11 18:49:21 by jeportie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 			so_long.a
CC = 			cc
CFLAGS = 		-Wall -Wextra -g3 -Iinclude -Ilibft -Iminilibx
OBJ_DIR = 		obj
OUTPUT_DIR = 	outputs
EXEC_DIR = 		exec
VALGRIND = 		valgrind --track-origins=yes --leak-check=full
LIBFT_DIR = 	libft
MINILIBX_DIR = 	minilibx
LIBS = 			-L$(MINILIBX_DIR) -lmlx -L$(LIBFT_DIR) -lft -lXext -lX11 -ldl -lglfw -pthread -lm

UTILITIES = 	$(addprefix src/utilities_src/, ft_exit_failure.c ft_display_controls.c\
					ft_flood_fill.c)

MAP_PARSER =	$(addprefix src/map_parser_src/, ft_check_map.c ft_parse_map.c \
					ft_read_map.c ) 

MAP_RENDER = 	$(addprefix src/map_render_src/, ft_render_map.c)

TILESET_PARS = 	$(addprefix src/tileset_parser_src/, ft_parse_tileset.c ft_load_tileset.c)

GARBAGE	=		$(addprefix src/gc_src/, garbage_collector.c gc_collect.c)

#TESTS =			test/tileset_tests.c

OBJ_UTILITIES =	$(UTILITIES:src/utilities_src/%.c=$(OBJ_DIR)/utilities_src_%.o)
OBJ_MAP_PARSE =	$(MAP_PARSER:src/map_parser_src/%.c=$(OBJ_DIR)/map_parser_src_%.o)
OBJ_MAP_REND  =	$(MAP_RENDER:src/map_render_src/%.c=$(OBJ_DIR)/map_render_src_%.o)
OBJ_TILESET	=	$(TILESET_PARS:src/tileset_parser_src/%.c=$(OBJ_DIR)/tileset_parser_src_%.o)
OBJ_GARBAGE	=	$(GARBAGE:src/gc_src/%.c=$(OBJ_DIR)/gc_src_%.o)
#OBJ_TESTS	=	$(TESTS:test/%.c=$(OBJ_DIR)/test_%.o)
OBJ =			$(OBJ_MAP_PARSE) $(OBJ_MAP_REND) $(OBJ_UTILITIES) $(OBJ_TILESET) \
				$(OBJ_GARBAGE) $(OBJ_TESTS)

all: $(LIBFT_DIR)/libft.a $(MINILIBX_DIR)/libmlx.a $(NAME)

$(LIBFT_DIR)/libft.a:
	make -C $(LIBFT_DIR)

$(MINILIBX_DIR)/libmlx.a:
	make -C $(MINILIBX_DIR)

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

$(OBJ_DIR)/tileset_parser_src_%.o: src/tileset_parser_src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/gc_src_%.o: src/gc_src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

#$(OBJ_DIR)/test_%.o: test/%.c
#	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

eclean: fclean
	rm -rf $(EXEC_DIR)

re: fclean all

main: all $(OBJ_DIR)/main.o
	mkdir -p $(EXEC_DIR)
	$(CC) $(CFLAGS) -o $(EXEC_DIR)/so_long $(OBJ_DIR)/main.o $(NAME) $(LIBS)

run: all $(OBJ_DIR)/main.o
	mkdir -p $(EXEC_DIR)
	$(CC) $(CFLAGS) -o $(EXEC_DIR)/so_long $(OBJ_DIR)/main.o $(NAME) $(LIBS); \
	./$(EXEC_DIR)/so_long "assets/maps/test_map.ber" | cat -e

debug: all $(OBJ_DIR)/main.o
	mkdir -p $(EXEC_DIR)
	$(CC) $(CFLAGS) -o $(EXEC_DIR)/so_long $(OBJ_DIR)/main.o $(NAME) $(LIBS); \
	$(VALGRIND) ./$(EXEC_DIR)/so_long "assets/maps/test_map.ber"

lldb: all $(OBJ_DIR)/main.o
	mkdir -p $(EXEC_DIR)
	$(CC) $(CFLAGS) -o $(EXEC_DIR)/so_long $(OBJ_DIR)/main.o $(NAME) $(LIBS); \
	lldb $(EXEC_DIR)/so_long

$(OBJ_DIR)/main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o $@

.PHONY: all clean fclean re main eclean
