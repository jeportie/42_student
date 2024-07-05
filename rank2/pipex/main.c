/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:57:08 by jeportie          #+#    #+#             */
/*   Updated: 2024/07/05 15:41:08 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"
#include <fcntl.h>
#include <stdio.h>

// Function to simulate a process that will be completely freed
void process_one(void)
{
    int rows = 5;
    int cols = 5;
    int i;
    char **local_grid;

    // Allocate a 2D array (grid)
    local_grid = (char **)gc_malloc(rows * sizeof(char *));
    gc_add_local_root((void**)&local_grid);
    for (i = 0; i < rows; i++)
    {
        local_grid[i] = (char *)gc_malloc(cols * sizeof(char));
    }
    // Fill the grid with some values
    for (i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            local_grid[i][j] = 'A' + j;
        }
    }

    // Perform some operations with the grid
    for (i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            ft_printf("%c ", local_grid[i][j]);
        }
        ft_printf("\n");
    }

    // Remove local root to simulate freeing
    gc_remove_local_root((void**)&local_grid);
    gc_collect();
}

// Function to simulate a process that remains in use
void process_two(void)
{
    int fd;
    char *local_line;

    // Open a file and read lines using get_next_line
    fd = open("example.tkt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return;
    }
    gc_fd_register(fd);

    // Read and print lines from the file
    local_line = get_next_line(fd);
    gc_add_local_root((void**)&local_line);
    while (local_line != NULL)
    {
        ft_printf("%s", local_line);
        local_line = get_next_line(fd);
    }

    // Remove all local roots and collect garbage
    gc_collect();
    close(fd);
}

int main(void)
{
    char *lol;

    lol = gc_malloc(10000000);
    gc_add_root((void**)&lol); // Add lol as a root

    for (int i = 0; i < 100; i++)
    {
        lol[i] = 'a';
    }
    ft_printf("Starting process_one...\n");
    process_one();

    ft_printf("\nStarting process_two...\n");
    process_two();

    ft_printf("\nEnding program...\n");

    lol[30] = 'a';
    // No gc_cleanup call to check for memory leaks with Valgrind
    gc_cleanup();

    return 0;
}

