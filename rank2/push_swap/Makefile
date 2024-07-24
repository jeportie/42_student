# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeportie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/24 11:04:02 by jeportie          #+#    #+#              #
#    Updated: 2024/07/24 16:04:50 by jeportie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 			push_swap
BONUS =			checker
CC = 			cc
CFLAGS = 		-Wall -Wextra -Werror -g3 -Iinclude -Ilibft
OBJ_DIR = 		obj
LIBFT_DIR = 	libft
LIBS = 			-L$(LIBFT_DIR) -lft

SRC_MAIN = 		main.c

SRC = 			$(addprefix src/, ft_lst_utils.c ft_check_errors.c ft_push_moves.c \
				ft_swap_moves.c ft_rotate_moves.c ft_rev_rotate_moves.c \
				ft_sort_utils.c ft_utils.c ft_sort.c \
				ft_calcul_cost.c ft_multi_rotate.c ft_define_segment.c \
				ft_parse.c ft_sort_a.c ft_sort_b.c ft_init_stack.c)

SRC_BONUS = 	$(addprefix bonus/, ft_main_checker.c ft_checker_moves.c \
				ft_checker.c ft_checker_utils.c)

OBJ =			$(addprefix $(OBJ_DIR)/, $(SRC:src/%.c=src/%.o))
MAIN_OBJ = 		$(addprefix $(OBJ_DIR)/, $(SRC_MAIN:%.c=%.o))
BONUS_OBJ = 	$(addprefix $(OBJ_DIR)/, $(SRC_BONUS:bonus/%.c=bonus/%.o))

all: $(LIBFT_DIR)/libft.a $(NAME)

$(LIBFT_DIR)/libft.a:
	@echo "\nCreating libft.a\n"
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ_DIR) $(MAIN_OBJ) $(OBJ)
	@echo "\nCreating push_swap\n"
	$(CC) $(CFLAGS) $(MAIN_OBJ) $(OBJ) -o $(NAME) $(LIBS)
	@echo "\npush_swap DONE\n"

$(BONUS): $(OBJ_DIR) $(OBJ) $(BONUS_OBJ)
	@echo "\nCreating bonus checker\n"
	$(CC) $(CFLAGS) $(OBJ) $(BONUS_OBJ) -o $(BONUS) $(LIBS)
	@echo "\nBonus DONE\n"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)/src $(OBJ_DIR)/bonus

$(OBJ_DIR)/src/%.o: src/%.c
	@mkdir -p $(dir $@)
	@echo "Compiling $< into $@"
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/bonus/%.o: bonus/%.c
	@mkdir -p $(dir $@)
	@echo "Compiling $< into $@"
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "Compiling $< into $@"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "\nCleaning object files\n"
	rm -f $(OBJ) $(MAIN_OBJ) $(BONUS_OBJ)
	rm -rf $(OBJ_DIR)
	@cd $(LIBFT_DIR) && $(MAKE) clean

fclean: clean
	@echo "\nFull clean\n"
	rm -f $(NAME) $(BONUS)
	@cd $(LIBFT_DIR) && $(MAKE) fclean

re: fclean all

bonus: $(BONUS)

.PHONY: all clean fclean re bonus

