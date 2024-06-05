# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 19:12:55 by jeportie          #+#    #+#              #
#    Updated: 2024/06/05 21:20:13 by jeportie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 			so_long.a
CC = 			cc
CFLAGS = 		-Wall -Wextra -g3 -I./include
OBJ_DIR = 		obj
OUTPUT_DIR = 	outputs
EXEC_DIR = 		exec
VALGRIND = 		valgrind --track-origins=yes --leak-check=full
LIBS = 			-Lminilibx -lX11 -lXext -lXrandr -lXrender

UTILITIES = 	$(addprefix src/utilities_src/, )

SRC =			$(addprefix src/, ) 

PRINTF_SRC =	$(addprefix ft_printf/, ft_apply_precision.c ft_handle_char.c \
			 	ft_handle_pointer.c ft_nbr_len.c ft_utoa_base.c ft_apply_width.c \
			 	ft_handle_hash_flag.c ft_handle_space_flag.c ft_parse_flags.c \
			 	ft_buffer_add.c ft_handle_hexadecimal.c ft_handle_string.c \
			 	ft_parse_format.c ft_printf_globals.c ft_buffer_flush.c \
			 	ft_handle_int.c ft_isconvert_spec.c ft_printf.c ft_check_format.c \
			 	ft_handle_plus_flag.c ft_isflag.c ft_ulltoa_base.c)

LIBFT_SRC = 	$(addprefix libft/, ft_atoi.c ft_atol.c ft_bzero.c ft_isalnum.c \
            	ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
            	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
            	ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \
            	ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
            	ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
            	ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
            	ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
            	ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
            	ft_toupper.c ft_calloc.c ft_realloc.c get_next_line.c)

MINILIBX_SRC = 	$(addprefix minilibx/, mlx_clear_window.c \
   				mlx_destroy_display.c mlx_destroy_image.c \
				mlx_destroy_window.c mlx_expose_hook.c mlx_ext_randr.c \
    			mlx_flush_event.c mlx_get_color_value.c mlx_get_data_addr.c \
    			mlx_hook.c mlx_init.c mlx_int_anti_resize_win.c mlx_int_do_nothing.c \
    			mlx_int_get_visual.c mlx_int_param_event.c mlx_int_set_win_event_mask.c \
    			mlx_int_str_to_wordtab.c mlx_int_wait_first_expose.c \
    			mlx_key_hook.c mlx_loop.c mlx_loop_hook.c \
    			mlx_mouse.c mlx_mouse_hook.c mlx_new_image.c mlx_new_window.c \
    			mlx_pixel_put.c mlx_put_image_to_window.c mlx_rgb.c \
    			mlx_screen_size.c mlx_set_font.c mlx_string_put.c mlx_xpm.c \
				mlx_xpm_file_to_image.c)
#mlx_lib_xpm.c 


OBJ_UTILITIES =	$(UTILITIES:src/utilities_src/%.c=$(OBJ_DIR)/%.o)
OBJ_SRC =		$(SRC:src/%.c=$(OBJ_DIR)/%.o)
OBJ_PRINTF =	$(PRINTF_SRC:ft_printf/%.c=$(OBJ_DIR)/%.o)
OBJ_LIBFT =		$(LIBFT_SRC:libft/%.c=$(OBJ_DIR)/%.o)
OBJ_MINILIBX =	$(MINILIBX_SRC:minilibx/%.c=$(OBJ_DIR)/%.o)
OBJ =			$(OBJ_SRC) $(OBJ_PRINTF) $(OBJ_LIBFT) $(OBJ_MINILIBX) $(OBJ_UTILITIES)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)


$(OBJ_DIR)/%.o: src/utilities_src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: ft_printf/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: libft/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: minilibx/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	
eclean: fclean
	rm -rf $(EXEC_DIR)

re: fclean all


main: all $(NAME) $(OBJ_DIR)/main.o
	mkdir $(EXEC_DIR)
	$(CC) $(C_FLAGS) -o $(EXEC_DIR)/so_long $(OBJ_DIR)/main.o $(NAME) $(LIBS);

debug: all $(NAME) $(OBJ_DIR)/main.o
	mkdir $(EXEC_DIR)
	$(CC) $(C_FLAGS) -o $(EXEC_DIR)/so_long $(OBJ_DIR)/main.o $(NAME) $(LIBS); \
	$(VALGRIND) ./$(EXEC_DIR)/so_long
	
lldb: all $(NAME) $(OBJ_DIR)/main.o
	mkdir $(EXEC_DIR)
	$(CC) $(C_FLAGS) -o $(EXEC_DIR)/push_swap $(OBJ_DIR)/main.o $(NAME) $(LIBS); \
	lldb $(EXEC_DIR)/push_swap

$(OBJ_DIR)/main.o: main.c
	$(CC) $(C_FLAGS) -c main.c -o $(OBJ_DIR)/main.o

.PHONY: all clean fclean re main eclean
