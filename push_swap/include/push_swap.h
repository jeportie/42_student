/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:24:54 by jeportie          #+#    #+#             */
/*   Updated: 2024/03/26 18:56:03 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "libft.h"
# include "printf.h"

typedef struct	s_dcnode
{
	long			value;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_node	*target;
	struct s_dcnode	*back;
	struct s_dcnode	*next;
}	t_dcnode;

typedef struct	s_dclst
{
	int				length;
	struct s_dcnode	*begin;
	struct s_dcnode	*end;
}	t_dclst;

/* Stack Operations */
void	sa(t_dclst *stack_a);
void	sb(t_dclst *stack_b);
void	ss(t_dclst *stack_a, t_dclst *stack_b);
void	pa(t_dclst *stack_a, t_dclst *stack_b);
void	pb(t_dclst *stack_a, t_dclst *stack_b);
void	ra(t_dclst *stack_a);
void	rb(t_dclst *stack_b);
void	rr(t_dclst *stack_a, t_dclst *stack_b);
void	rra(t_dclst *stack_a);
void	rrb(t_dclst *stack_b);
void	rrr(t_dclst *stack_a, t_dclst *stack_b);
void	noprint_sa(t_dclst *stack_a);
void	noprint_sb(t_dclst *stack_b);
void	noprint_ra(t_dclst *stack_a);
void	noprint_rb(t_dclst *stack_b);
void	noprint_rra(t_dclst *stack_a);
void	noprint_rrb(t_dclst *stack_b);

/* Push_swap QuickSort (PHASE 1 BIG_DATA)*/
/* Push_swap RadixSort (PHASE 2 BIG DATA)*/
void	radix_sort(t_dclst *stack_a, t_dclst *stack_b);
int		ft_find_max_bits(t_dclst *stack);
long	ft_find_max(t_dclst *stack);
void	ft_apply_bitwise_sort(t_dclst *stack_a, t_dclst *stack_b, int bit);
bool	ft_check_bit(long number, int bit);
void	ft_perform_push_or_rotate(t_dclst *stack_a, t_dclst *stack_b, int bit);
void	ft_reintegrate_stack_b(t_dclst *stack_a, t_dclst *stack_b);

/* Turkish Algo strategy (MEDIUM_DATA) */
void	turkish_sort(t_dclst *stack_a, t_dclst *stack_b);
	void	ft_push_initial_numbers(t_dclst *stack_a, t_dclst *stack_b);
	void	ft_define_target(t_dclst *stack_a, t_dclst *stack_b);
		t_dcnode* ft_closest_smaller_number(t_dclst *stack_a, t_dclst *stack_b);
		// if our node value is smaller than any possible target in stack_b, then assign
		// it to the max value of stack_b (that way it will take the place as smalest value)
	void	ft_isabove_median(t_dclst *stack_a, t_dclst *stack_b);
	void	ft_calculate_push_cost(t_dclst *stack_a, t_dclst *stack_b);
	void	ft_define_cheapest_node(t_dclst *stack_a);
	void	ft_push_to_target(t_dclst *stack_a, t_dclst *stack_b);
		// use push cost value to determine if we can do rrr instead of rb ra.
		void	ft_init_push_cost(t_dclst *stack_a);
	void	ft_sort_three(t_dclst *stack_a);
	void	ft_back_to_stack_a(t_dclst *stack_a, t_dclst *stack_b);
	void	ft_fine_tune(t_dclst *stack_a);
/* Small Data Sorting Algos (SMALL DATA)*/

/* Utility functions */
int		ft_stack_size(t_dclst *stack);
bool	ft_isempty(t_dclst *stack);
bool	ft_validate_inputs(int argc, char **argv);
bool	ft_isinteger(char *str);
void	ft_init_stack(t_dclst **stack);
void	ft_empty_stack(t_dclst *stack);
void	ft_parse_arg(int argc, char **argv, t_dclst *stack_a);
void	ft_push_to_stack(t_dclst *stack, long value);
void    ft_print_stack(t_dclst *stack, char name);
int		ft_argc_len(char **argv);
void	ft_free_split(char **argv);

#endif /*PUSH_SWAP*/	
