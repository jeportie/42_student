/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:57:08 by jeportie          #+#    #+#             */
/*   Updated: 2024/06/01 23:14:05 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"
#include "include/so_long.h"
#include "include/mlx.h"
#include "include/ft_printf.h"

int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init(); 
	win_ptr = mlx_new_window(mlx_ptr, 800, 600, "Hello Jerome !");
	mlx_loop(mlx_ptr);

	mlx_destroy_window(mlx_ptr, win_ptr);
	free(mlx_ptr);
	return (0);
}
