/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:46:51 by jeportie          #+#    #+#             */
/*   Updated: 2024/01/24 02:12:13 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    int i;
    char *test;

    fd = open("testfile.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening test file:");
        exit(EXIT_FAILURE);
    }
    i = 1;
    while ((test = get_next_line(fd)) != NULL)
    {
        printf("l%i: %s", i, test);
        free(test);  // Free the memory allocated by get_next_line
        i++;
    }
    close(fd);  // Close the file descriptor
    return (0);
}
