/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:24:54 by jeportie          #+#    #+#             */
/*   Updated: 2024/03/19 16:21:56 by jeportie         ###   ########.fr       */
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

typedef struct	s_dcnode
{
	int	value;
	struct s_dcnode	*back;
	struct s_dcnode	*next;_
}	t_dcnode;

typedef struct s_dclst
{
	int	lenght;
	struct t_dcnode	*begin;
	struct t_dcnode	*end;
}	t_dclst;

#endif /*PUSH_SWAP*/
