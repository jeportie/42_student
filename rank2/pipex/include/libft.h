/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:59:02 by jeportie          #+#    #+#             */
/*   Updated: 2024/03/22 17:31:27 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>
# include <stdarg.h>


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_buffer
{
	char	*buffer;
	int		index;
	int		nb_printed;
	int		error;
	char	buf_last;
}			t_buffer;

typedef struct s_format_spec
{
	int			width;
	int			precision;
	int			flag_minus;
	int			flag_zero;
	int			flag_hash;
	int			flag_space;
	int			flag_plus;
	char		type;
	int			error;
}				t_format_spec;

typedef enum e_error
{
	NOERR,
	ERNOWRITE,
	ERNOMEM,
	ERNOFORMAT,
}	t_error;


/*		Partie 1 - Fonctions de la libc  */
int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_tolower(int c);
int		ft_toupper(int c);

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t len);

char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);

size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);

//		Partie 2 - Fonctions supplementaires
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *S, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/*		Partie Bonus  */
int		ft_lstsize(t_list *lst);

t_list	*ft_lstnew(void	*content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

void	ft_lstadd_front(t_list **lst, t_list *New);
void	ft_lstadd_back(t_list **lst, t_list *New);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));

/* GNL */
char	*get_next_line(int fd);
char	*ft_read_buffer(int fd, char *buffer);
char	*ft_extract_line(char *buffer);
char	*ft_update_buffer(char *buffer);
char	*ft_strjoin_gnl(char const *s1, char const *s2);

/* PRINTF */
extern const char	*g_perror[];

int				ft_printf(const char *format, ...);
int				ft_isflag(char c);
int				ft_isconvert_spec(char c);

//type conversion functions
char			*ft_utoa_base(unsigned int nbr, char *base);
char			*ft_ulltoa_base(unsigned long long nbr, char *base);
int				ft_nbr_len(unsigned long long nbr, int base_len);
//format spec functions
t_format_spec	ft_parse_format(const char **format);
void			ft_parse_flags(const char *format, t_format_spec *spec);

int				ft_check_format(t_format_spec *spec);
void			ft_apply_width(t_format_spec spec, t_buffer *buf_info,
					int content_len);
void			ft_apply_precision(t_format_spec spec,
					char **formatted_content);
void			ft_handle_hash_flag(t_format_spec spec, int content,
					t_buffer *buf_info);
void			ft_handle_space_flag(t_format_spec spec, int content,
					t_buffer *buf_info);
void			ft_handle_plus_flag(t_format_spec spec, int content,
					t_buffer *buf_info);
//Conversion functions
void			ft_handle_char(t_format_spec spec, va_list args,
					t_buffer *buf_info);
void			ft_handle_string(t_format_spec spec, va_list args,
					t_buffer *buf_info);
int				ft_handle_pointer(t_format_spec spec, va_list args,
					t_buffer *buf_info);
int				ft_handle_int(t_format_spec spec, va_list args,
					t_buffer *buf_info);
int				ft_handle_hexadecimal(t_format_spec spec, va_list args,
					t_buffer *buf_info);
//buffer management
void			ft_buffer_add(t_buffer *buf_info, char c);
int				ft_buffer_flush(t_buffer *buf_info);


#endif /*LIBFT_H*/
