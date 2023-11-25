/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filemanip.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:03:38 by jeportie          #+#    #+#             */
/*   Updated: 2023/11/25 17:25:55 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEMANIP_H
# define FILEMANIP_H

# define FLINE_BUFFER_SIZE 512

# include <fcntl.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft_project_Nov23/libft/libft.h"

typedef struct s_tstlst
{
	char				*title;
	char				*test_value;
	char				*description;
	struct s_testlst	*next;
}						t_tstlst;

//FUNCTION THAT OPEN AND CLOSES THE FILE INSIDE THE FUNCTION
size_t	ft_filesize(const char *filepath);
int		ft_count_flines(const char *filepath);
char	**ft_flines_to_str(const char *filepath);
//FUNCTION THAT WORKS WITH THE FILE DESCRIPTOR OF AN OPEN FILE
int		ft_fopen(const char *filepath, int option);
char	*ft_fread(int fd, size_t len);
int		ft_fclose(int fd);
//TEST LIST FILE FUNCTIONS
t_tstlst	*ft_load_tests(const char *filepath);
t_tstlst	*ft_parse_line_to_test(const char *line);
t_tstlst	*ft_testlst_new(char *title, char *value, char *description);
void		ft_testlst_add_back(t_tstlst **lst, t_tstlst *new);
void		ft_testlst_delone(t_tstlst *lst, void (*del)(void*));
void		ft_testlst_clear(t_tstlst **lst, void (*del)(void*));
void		ft_print_testlst(t_tstlst *lst);
void	ft_free_memory(char **tab, size_t i);
void		ft_free_node(void *node);
#endif /*FILEMANIP_H*/
