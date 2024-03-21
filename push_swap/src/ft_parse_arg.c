/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:24:17 by jeportie          #+#    #+#             */
/*   Updated: 2024/03/21 17:49:52 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_parse_arg(int argc, char **argv, t_dclst *stack_a);

/*
 * 3 parsing format :
 * One value per argument:
 * 		-ft_valid_input
 * 		-ft_is_integer
 * 		-ft_addto_stack with the help of ft_atol
 * All the value in one string argument:
 * 		-make a function to detect separators
 * 		-ft_split
 * 		- one value per arg process
 * The filepath of a file with all values on it:
 * 		-
 */
