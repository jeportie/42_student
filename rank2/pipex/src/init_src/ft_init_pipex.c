/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 12:13:47 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/08 19:24:23 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	ft_init_pipex(t_pipex *pipex, int argc, char **argv)
{
	ft_parse_args(pipex, argc, argv);
//	gc_collect();
//	ft_setup_pipes(pipex);
//	gc_collect();
	ft_open_files(pipex);
}
