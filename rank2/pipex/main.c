/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:57:08 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/15 20:05:51 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	ft_init_pipex(&pipex, argc, argv, envp);
	ft_fork_and_exec(&pipex, envp);
	gc_cleanup();
	return (EXIT_SUCCESS);
}
