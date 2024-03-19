/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:24:54 by jeportie          #+#    #+#             */
/*   Updated: 2024/03/19 13:47:30 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
// add GNL and printf in libft !
#include "printf.h"

typedef enum
{
	false,
	true
}	Bool;

typedef struct	s_dc_node
{
	int	value;
	struct s_dc_node	*back;
	struct s_dc_node	*next;_
}	t_dc_node;

typedef struct s_dclst
{
	int	lenght;
	struct t_dc_node	*begin;
	struct t_dc_node	*end;
}	t_dclst;

#endif /*PUSH_SWAP*/
