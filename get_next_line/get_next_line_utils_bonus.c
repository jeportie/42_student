/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 08:59:54 by jeportie          #+#    #+#             */
/*   Updated: 2024/02/08 22:58:24 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;

	if (new_size <= old_size)
		return (ptr);
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	if (ptr)
	{
		ft_memcpy(new_ptr, ptr, old_size);
		free(ptr);
	}
	return (new_ptr);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*mem_dest;
	unsigned char	*mem_src;

	if (!dest && !src)
		return (NULL);
	mem_dest = (unsigned char *)dest;
	mem_src = (unsigned char *)src;
	while (n-- && mem_dest && mem_src)
		*mem_dest++ = *mem_src++;
	return (dest);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*mem_src;

	mem_src = (unsigned char *)s;
	while (n--)
		*mem_src++ = (unsigned char)c;
	return (s);
}

char	*ft_strchr(const char *s, int c)
{
	char	first_occurrence;

	if (!s)
		return (NULL);
	first_occurrence = (unsigned char)c;
	while (*s)
	{
		if (*s == first_occurrence)
			return ((char *)s);
		s++;
	}
	if (first_occurrence == '\0')
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

t_fd_list	*ft_find_fd(t_fd_list **top, int fd)
{
	t_fd_list	*result;

	result = *top;
	while (result)
	{
		if (result->fd == fd)
			return (result);
		result = result->next;
	}
	return (NULL);
}

t_fd_list	*ft_list_new(int fd)
{
	t_fd_list	*new_node;

	new_node = (t_fd_list *)malloc(sizeof(t_fd_list));
	if (!new_node)
		return (NULL);
	new_node->fd = fd;
	new_node->buffer = NULL;
	new_node->next = NULL;
	return (new_node);
}

t_fd_list	*ft_lstlast(t_fd_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_fd_list **lst, t_fd_list *new)
{
	t_fd_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

void	ft_lstdelone(t_fd_list **lst, int fd)
{
	t_fd_list	*to_delete;
	t_fd_list	*prev;

	to_delete = *lst;
	prev = NULL;
	while (to_delete != NULL)
	{
		if (to_delete->fd == fd)
		{
			if (!prev)
				*lst = to_delete->next;
			else
				prev->next = to_delete->next;
			free(to_delete->buffer);
			free(to_delete);
			return ;
		}
		prev = to_delete;
		to_delete = to_delete->next;
	}
}
