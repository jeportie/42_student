/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:24:54 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/18 11:24:27 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "libft.h"
# include "printf.h"

typedef struct s_dcnode
{
	long			value;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	int				moves_to_top;
	int				combined_moves;
	struct s_dcnode	*target;
	struct s_dcnode	*back;
	struct s_dcnode	*next;
}	t_dcnode;

typedef struct s_dclst
{
	int				length;
	struct s_dcnode	*begin;
	struct s_dcnode	*end;
}	t_dclst;

/* Stack Operations */
void		sa(t_dclst *stack_a, bool print);
void		sb(t_dclst *stack_b, bool print);
void		ss(t_dclst *stack_a, t_dclst *stack_b);
void		pa(t_dclst *stack_a, t_dclst *stack_b);
void		pb(t_dclst *stack_a, t_dclst *stack_b);
void		ra(t_dclst *stack_a, bool print);
void		rb(t_dclst *stack_b, bool print);
void		rr(t_dclst *stack_a, t_dclst *stack_b);
void		rra(t_dclst *stack_a, bool print);
void		rrb(t_dclst *stack_b, bool print);
void		rrr(t_dclst *stack_a, t_dclst *stack_b);

/* Turkish Algo strategy */
void		turkish_sort(t_dclst *stack_a, t_dclst *stack_b);
t_dcnode	*ft_ischeapest(t_dclst *stack);
void		ft_push_initial_numbers(t_dclst *stack_a, t_dclst *stack_b);
void		ft_actualise_indexes(t_dclst *stack_a, t_dclst *stack_b);
void		ft_define_index(t_dclst *stack);
void		ft_define_target(t_dclst *stack_a, t_dclst *stack_b);
t_dcnode	*ft_closest_smaller_number(t_dcnode *node_a, t_dclst *stack_b);
t_dcnode	*ft_closest_greater_number(t_dcnode *node_b, t_dclst *stack_a);
void		ft_isabove_median(t_dclst *stack_a, t_dclst *stack_b);
void		ft_mark_above_median(t_dclst *stack);
void		ft_calculate_push_cost(t_dclst *stack_a, t_dclst *stack_b);
int			ft_moves_to_top(t_dclst *stack, t_dcnode *node);
void		ft_push_to_target(t_dclst *stack_a, t_dclst *stack_b);
void		ft_sort_three(t_dclst *stack_a);
void		ft_back_to_stack_a(t_dclst *stack_a, t_dclst *stack_b);
void		ft_fine_tune(t_dclst *stack_a);

/* Utility functions */
bool		ft_is_sort(t_dclst *stack_a);
long		ft_labs(long value);
int			ft_stack_size(t_dclst *stack);
bool		ft_isempty(t_dclst *stack);
bool		ft_validate_inputs(int argc, char **argv);
bool		ft_isinteger(char *str);
void		ft_init_stack(t_dclst **stack);
void		ft_empty_stack(t_dclst *stack);
void		ft_parse_arg(int argc, char **argv, t_dclst *stack_a);
void		ft_push_to_stack(t_dclst *stack, long value);
void		ft_print_stack(t_dclst *stack, char name);
int			ft_argc_len(char **argv);
void		ft_free_split(char **argv);

#endif /*PUSH_SWAP*/	
