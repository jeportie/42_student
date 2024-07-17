# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 19:12:55 by jeportie          #+#    #+#              #
#    Updated: 2024/07/17 08:45:39 by jeportie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 			so_long.a
CC = 			cc
CFLAGS = 		-Wall -Wextra -Werror -g3 -Iinclude -Ilibft -Iminilibx
OBJ_DIR = 		obj
OUTPUT_DIR = 	outputs
EXEC_DIR = 		exec
VALGRIND = 		valgrind \
				--track-origins=yes \
				--leak-check=full \
			#	--tool=helgrind

LIBFT_DIR = 	libft
MINILIBX_DIR = 	minilibx
LIBS = 			-L$(MINILIBX_DIR) -lmlx -L$(LIBFT_DIR) -lft -lXext -lX11 -ldl -lglfw -pthread -lm

UTILITIES = 	$(addprefix src/utilities_src/, \
				ft_blend_images.c \
				ft_count_lines.c \
				ft_display_controls.c \
				ft_exit_failure.c \
				ft_flood_fill.c \
				ft_init_game.c \
				ft_start_display.c)

MAP_PARSER =	$(addprefix src/map_parser_src/, \
				ft_check_char.c \
				ft_check_door.c \
				ft_check_fill.c \
				ft_check_map.c \
				ft_check_wall.c \
				ft_chek_rectangle.c \
				ft_count_collectibles.c \
				ft_parse_map.c \
				ft_read_map.c) 

MAP_RENDER = 	$(addprefix src/map_render_src/, \
				ft_clear_buffer.c \
				ft_get_tile.c \
				ft_put_tile_to_buffer.c \
				ft_render_game.c \
				ft_render_map.c \
				ft_render_obj.c \
				ft_render_player.c)

TILESET_PARS = 	$(addprefix src/tileset_parser_src/, \
				ft_check_tilelist.c \
				ft_get_tile.c \
				ft_load_tileset.c \
				ft_parse_tileset.c)

EVENTS = 		$(addprefix src/events_src/, \
				ft_check_exit.c \
				ft_init_player_anim.c \
				ft_move_player.c \
				ft_player_anim.c \
				ft_render_goblin_anim.c \
				ft_render_info.c \
				ft_render_player_anim.c \
				ft_update_goblin_move.c \
				ft_update_goblin_position.c \
				ft_update_player_move.c \
				ft_update_position.c)

GARBAGE	=		$(addprefix src/gc_src/, \
				ft_clean_tiles.c )

OBJ_UTILITIES =	$(UTILITIES:src/utilities_src/%.c=$(OBJ_DIR)/utilities_src_%.o)
OBJ_MAP_PARSE =	$(MAP_PARSER:src/map_parser_src/%.c=$(OBJ_DIR)/map_parser_src_%.o)
OBJ_MAP_REND  =	$(MAP_RENDER:src/map_render_src/%.c=$(OBJ_DIR)/map_render_src_%.o)
OBJ_TILESET	=	$(TILESET_PARS:src/tileset_parser_src/%.c=$(OBJ_DIR)/tileset_parser_src_%.o)
OBJ_GARBAGE	=	$(GARBAGE:src/gc_src/%.c=$(OBJ_DIR)/gc_src_%.o)
OBJ_EVENTS	=	$(EVENTS:src/events_src/%.c=$(OBJ_DIR)/events_src_%.o)
OBJ =			$(OBJ_MAP_PARSE) $(OBJ_MAP_REND) $(OBJ_UTILITIES) $(OBJ_TILESET) \
				$(OBJ_GARBAGE) $(OBJ_EVENTS)

all: $(LIBFT_DIR)/libft.a $(MINILIBX_DIR)/libmlx.a $(NAME) copy_mlx_header

$(LIBFT_DIR)/libft.a:
	make -C $(LIBFT_DIR)

$(MINILIBX_DIR)/libmlx.a: 
	@if [ ! -d "$(MINILIBX_DIR)" ]; then \
		echo "Minilibx not found, cloning..."; \
		git clone https://github.com/42Paris/minilibx-linux.git $(MINILIBX_DIR); \
	fi
	make -C $(MINILIBX_DIR)

copy_mlx_header:
	@cp $(MINILIBX_DIR)/mlx.h include/

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

$(OBJ_DIR)/events_src_%.o: src/events_src/%.c
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
