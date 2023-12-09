/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfmanip.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:03:38 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/09 15:16:38 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEMANIP_H
# define FILEMANIP_H

# define FLINE_BUFFER_SIZE 512
# define LIBC 1
# define LIBFT 0

# include <fcntl.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <signal.h>
# include <sys/wait.h>
# include "libft.h"

typedef struct s_tstlst
{
	char				*title;
	char				**test_values;
	char				*description;
	struct s_tstlst		*next;
}						t_tstlst;

typedef enum
{
	ARG_INT,
	ARG_STRING
}t_arg;

// Function pointer type for int func(int)
typedef int (*func_int_int)(int);

// Function map structure
typedef struct s_funcmap_int_int
{
    const char		*name;
    func_int_int	ft_func;
    func_int_int	libc_func;
} 					t_funcmap_int_int;

// Function Map Array
extern t_funcmap_int_int g_func_map_int_int[]; 

//FUNCTION THAT OPEN AND CLOSES THE FILE INSIDE THE FUNCTION
size_t		    ft_filesize(const char *filepath);
int			    ft_count_flines(const char *filepath);
char		    **ft_flines_to_str(const char *filepath);
//FUNCTION THAT WORKS WITH THE FILE DESCRIPTOR OF AN OPEN FILE
int			    ft_fopen(const char *filepath, int option);
char		    *ft_fread(int fd, size_t len);
int			    ft_fclose(int fd);
//TEST LIST FILE FUNCTIONS
char		    *ft_testfile_option_format(char *s);
t_tstlst	    *ft_load_tests(const char *filepath);
t_tstlst	    *ft_parse_line_to_test(const char *line);
t_tstlst	    *ft_testlst_new(char *title, char **values, int num_values, char *description);
void		    ft_testlst_add_back(t_tstlst **lst, t_tstlst *new);
void		    ft_testlst_delone(t_tstlst *lst, void (*del)(void*));
void		    ft_testlst_clear(t_tstlst **lst, void (*del)(void*));
void		    ft_print_testlst(t_tstlst *lst);
void		    ft_free_memory(char **tab, size_t i);
void		    ft_free_node(void *node);
void 		    ft_test_function(t_tstlst *lst, int (*libc_func)(), int (*ft_func)(),t_arg arg_type);
int	            ft_call_and_exec_cft(const char *name, int arg, int lib);
func_int_int    ft_call_ft(const char *name, int lib);

#endif /*FILEMANIP_H*/
