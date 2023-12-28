/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizettester_ssz.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:52:57 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/28 12:39:39 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftest.h"

size_t  ft_sizettester_ssz(size_t (*f)(), char *value1, char *value2, size_t value3)
{
    pid_t   pid;
    int     status;

    pid = fork();
    if (pid == -1)
    {
        perror("forking failed.");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        signal(SIGSEGV, SIG_DFL);
        f(value1, value2, value3);
        exit(EXIT_SUCCESS);
    }
    else
    {
        waitpid(pid, &status, 0);
        if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
            return (SEGFAULT);
        else
            return (f(value1, value2, value3));
    }
}
/*
** Maybe some issu with return (SEGFAULT)>  this functions returns size_t but 
** SEGFAULT = -666 so...
*/
