# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeportie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/24 11:04:02 by jeportie          #+#    #+#              #
#    Updated: 2024/07/24 13:05:51 by jeportie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
BONUS			= checker

SRC_MAIN		= main.c

SRC				= ft_lst_utils.c ft_check_errors.c\
				ft_push_moves.c ft_swap_moves.c ft_rotate_moves.c ft_rev_rotate_moves.c\
				ft_sort_utils.c ft_utils.c ft_sort.c \
				ft_calcul_cost.c ft_multi_rotate.c ft_define_segment.c \
				ft_parse.c ft_sort_a.c ft_sort_b.c ft_init_stack.c

SRC_BONUS		= ft_main_checker.c ft_checker_moves.c ft_checker.c ft_checker_utils.c\

CC				= cc
RM				= rm -f
FLAGS			= -Wall -Wextra -Werror -g3
LIBFTDIR		= libft/
OBJ_DIR			= obj/
SRC_DIR			= ./
BONUS_DIR		= bonus/

OBJ 			= ${addprefix ${OBJ_DIR},${SRC:.c=.o}}
MAIN_OBJ        = ${addprefix ${OBJ_DIR},${SRC_MAIN:.c=.o}}
BONUS_OBJ       = ${addprefix ${OBJ_DIR},${SRC_BONUS:.c=.o}}

INCLUDE 		= -L./libft -lft

${OBJ_DIR}%.o: ${SRC_DIR}%.c
	@mkdir -p $(OBJ_DIR)
	@echo "Compiling $< into $@"
	${CC} ${FLAGS} -c $< -o $@

${OBJ_DIR}%.o: ${BONUS_DIR}%.c
	@mkdir -p $(OBJ_DIR)
	@echo "Compiling $< into $@"
	${CC} ${FLAGS} -c $< -o $@

.c.o:
	@echo "Compiling $< into ${<:.c=.o}"
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${MAIN_OBJ} ${OBJ}
	@echo "\nCreating libft.a\n"
	make -C $(LIBFTDIR)
	@echo "\nlibft DONE"
	@echo "\nCreating push_swap\n"
	${CC} ${FLAGS} ${MAIN_OBJ} ${OBJ} -o ${NAME} ${INCLUDE}
	@echo "\npush_swap DONE\n"

${BONUS}: ${OBJ} ${BONUS_OBJ}
	@echo "\nCreating libft.a\n"
	make -C $(LIBFTDIR)
	@echo "\nlibft DONE"
	@echo "\nCreating bonus checker\n"
	${CC} ${FLAGS} ${OBJ} ${BONUS_OBJ} -o ${BONUS} ${INCLUDE}
	@echo "\nBonus DONE\n"

all: ${NAME}

bonus: ${BONUS}

clean:
	${RM} -rf $(OBJ_DIR) ${NAME}
	@cd ${LIBFTDIR} && ${MAKE} clean

fclean: clean
	${RM} ${NAME} ${BONUS}
	@cd ${LIBFTDIR} && ${MAKE} fclean

re: fclean all bonus

.PHONY: all clean fclean re bonus
