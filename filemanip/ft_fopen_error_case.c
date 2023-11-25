/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fopen_error_case.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:14:07 by jeportie          #+#    #+#             */
/*   Updated: 2023/11/25 15:17:01 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filemanip.h"

void	ft_fopen_error_case(void)
{
	if (errno == ENOENT)
		perror("Error: No such file or directory");
	else if (errno == EACCES)
		perror("Error: Permission denied");
	else if (errno == EMFILE)
		perror("Error: Too many open files");
	else if (errno == ENFILE)
		perror("Error: File table overflow");
	else if (errno == EISDIR)
		perror("Error: Is a directory");
	else
		perror("Error: Unknown file open error");
}
