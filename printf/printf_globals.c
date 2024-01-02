/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_globals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 03:49:22 by jeportie          #+#    #+#             */
/*   Updated: 2024/01/02 03:49:48 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

const char	*g_perror[] = 
{
	"Success",
	"Error: Failed to write output",
	"Error: Memory allocation failed",
	"Error: Invalid format string",
};
