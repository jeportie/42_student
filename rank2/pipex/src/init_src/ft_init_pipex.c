/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 12:13:47 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/09 13:29:49 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	ft_init_pipex(t_pipex *pipex, int argc, char **argv)
{
	ft_parse_args(pipex, argc, argv);
//	gc_collect();
	pipex->prev_pipefd[0] = -1;
	pipex->prev_pipefd[1] = -1;
	ft_open_files(pipex);
}
