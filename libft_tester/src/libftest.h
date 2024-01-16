/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftest.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:03:38 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/28 14:24:56 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTEST_H
# define LIBFTEST_H

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
# include <string.h>
# include <bsd/string.h>
# include "../lib/libft.h"
# include "../lib/libfmanip.h"

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
	ARG_STRING,
	ARG_CONST_VOID,
	ARG_CONST_STRING,
	ARG_SIZE_T,
	ARG_UNKNOWN = -1
}	t_arg;

typedef enum
{
	RETURN_INT,
	RETURN_SIZE_T,
	RETURN_STR,
	RETURN_VOID
}	t_return;

typedef enum
{
	SEGFAULT = -666
}	t_segfault;

// Function pointer type to be more easy to handle.
typedef int		(*func_int)();
typedef	size_t	(*func_size_t)();
typedef char	*(*func_str)();

// Function map structure
typedef struct s_funcmap_int
{
    const char	*name;
    func_int	ft_func;
    func_int	libc_func;
	t_arg		*arg_types;
} 				t_funcmap_int;

typedef struct s_funcmap_size_t
{
    const char		*name;
    func_size_t		ft_func;
    func_size_t		libc_func;
	t_arg			*arg_types;
} 					t_funcmap_size_t;

typedef struct s_funcmap_str
{
	const char	*name;
	func_str	ft_func;
	func_str	libc_func;
	t_arg		*arg_types;
}				t_funcmap_str;

// Function Map Array
extern			t_funcmap_int g_func_map_int[]; 
extern			t_funcmap_size_t g_func_map_size_t[];
extern			t_funcmap_str g_func_map_str[]; 

//LOAD TEST FUNCTIONS
t_tstlst	    *ft_load_tests(const char *filepath);
//MAIN FUNCTIONS
t_tstlst	    *ft_parse_line_to_test(const char *line);
void		    ft_testlst_clear(t_tstlst **lst, void (*del)(void*));
void		    ft_testlst_add_back(t_tstlst **lst, t_tstlst *new);
void		    ft_free_memory(char **tab, size_t i);
//FILE AND LIST UTILITARIES
t_tstlst	    *ft_testlst_new(char *title, char **values, int num_values, char *description);
void		    ft_testlst_delone(t_tstlst *lst, void (*del)(void*));
void		    ft_free_node(void *node);

//RUN TEST FUNCTIONS
int				ft_run_test(const char *func_name);
//FUNCTION LOADER FUNCTIONS
func_int	    ft_call_func_int(const char *name, int lib);
func_size_t		ft_call_func_size_t(const char *name, int lib);
func_str 		ft_call_func_str(const char *name, int lib);
t_arg			*ft_find_ftparam_type(const char *name);
t_return		ft_find_ftreturn_type(const char *name);
//COMPARING LIBFT/LIBC FUNCTIONS - ONE PER FUNCTION SIGNATURE
void 			ft_inttest_for_int(int (*libc_func)(), int (*ft_func)(), t_tstlst *lst);
void			ft_inttest_for_str(int (*libc_func)(), int (*ft_func)(), t_tstlst *lst);
void 			ft_inttest_for_vvz(int (*libc_func)(), int (*ft_func)(), t_tstlst *lst);
void 			ft_inttest_for_ssz(int (*libc_func)(), int (*ft_func)(), t_tstlst *lst);
void			ft_sizettest_for_str(size_t (*libc_func)(), size_t (*ft_func)(), t_tstlst *lst);
void 			ft_sizettest_for_ssz(size_t (*libc_func)(), size_t (*ft_func)(), t_tstlst *lst);
void 			ft_strtest_for_str(func_str libc_func, func_str ft_func, t_tstlst *lst);
void 			ft_strtest_for_si(char *(*libc_func)(), char *(*ft_func)(), t_tstlst *lst);
void			ft_strtest_for_ssz(char *(*libc_func)(), char *(*ft_func)(), t_tstlst *lst);
char		    *ft_testfile_option_format(char *s);
//FORKING PROCESS FOR FUNCTION TO EXECUTE
int  			ft_inttester_int(int (*f)(), int value);
int  			ft_inttester_str(int (*f)(), char *value);
int  			ft_inttester_vvz(int (*f)(), void *value1, void *value2, size_t value3);
int  			ft_inttester_ssz(int (*f)(), char *value1, char *value2, size_t value3);
size_t			ft_sizettester_str(size_t (*f)(), char *value);
size_t			ft_sizettester_ssz(size_t (*f)(), char *value1, char *value2, size_t value3);
char			*ft_strtester_str(char *(*f)(), char *value);
char			*ft_strtester_si(char *(*f)(), char *value1, int value2);
char			*ft_strtester_ssz(char *(*f)(), char *value1, char *value2, size_t value3);
#endif /*LIBFTEST_H*/
