/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:57:08 by jeportie          #+#    #+#             */
/*   Updated: 2024/03/20 23:50:46 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"
#include "include/push_swap.h"
#include "include/ft_printf.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_printf("Programe name: %s\n", argv[0]);
		ft_printf("Hello, World! :)\n");
	}
	if (argc == 2)
		ft_printf("Hello, world!\nYou entered this input:\n%s\n", argv[1]);
	return (0);
}
