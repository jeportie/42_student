/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 22:20:47 by neleon            #+#    #+#             */
/*   Updated: 2024/05/29 00:25:21 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd, int flag)
{
	static char	*chars_rd[FD_MAX];
	char		*line;

	if (flag == 1)
	{
		free(*chars_rd);
		*chars_rd = NULL;
		return (NULL);
	}
	line = NULL;
	if (fd < 0 || fd > FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	chars_rd[fd] = gnl_read_and_store(fd, chars_rd[fd]);
	if (!chars_rd[fd])
		return (NULL);
	line = gnl_extract_line(&chars_rd[fd]);
	return (line);
}

char	*gnl_read_and_store(int fd, char *chars_rd)
{
	char	*buf;
	char	*tmp;
	ssize_t	bytes_rd;

	tmp = NULL;
	buf = gnl_intit_buf();
	bytes_rd = read(fd, buf, BUFFER_SIZE);
	while (bytes_rd > 0)
	{
		buf[bytes_rd] = '\0';
		tmp = gnl_strjoin(chars_rd, buf);
		free(chars_rd);
		chars_rd = tmp;
		if (gnl_strchr(buf, '\n'))
			break ;
		bytes_rd = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	if ((bytes_rd <= 0 && gnl_strlen(chars_rd) == 0))
	{
		free(chars_rd);
		return (NULL);
	}
	return (chars_rd);
}

char	*gnl_extract_line(char **chars_rd)
{
	char	*line;
	char	*buf;
	char	*newline_ptr;

	newline_ptr = gnl_strchr(*chars_rd, '\n');
	if (!newline_ptr)
	{
		line = gnl_strdup(*chars_rd);
		free(*chars_rd);
		*chars_rd = NULL;
	}
	else
	{
		line = gnl_substr(*chars_rd, 0, newline_ptr - *chars_rd + 1);
		buf = gnl_strdup(newline_ptr + 1);
		free(*chars_rd);
		*chars_rd = buf;
	}
	return (line);
}

char	*gnl_intit_buf(void)
{
	char	*buf;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
	{
		free(buf);
		return (NULL);
	}
	return (buf);
}

// int	main(void)
// {
// 	char	*line;
// 	int		i;
// 	int		fd1;
// 	int		fd2;
// 	int		fd3;

// 	fd1 = open("tests/test.txt", O_RDONLY);
// 	fd2 = open("tests/test2.txt", O_RDONLY);
// 	fd3 = open("tests/test3.txt", O_RDONLY);
// 	i = 1;
// 	while (i < 7)
// 	{
// 		line = get_next_line(fd1);
// 		printf("line [%02d]: %s", i, line);
// 		free(line);
// 		line = get_next_line(fd2);
// 		printf("line [%02d]: %s", i, line);
// 		free(line);
// 		line = get_next_line(fd3);
// 		printf("line [%02d]: %s", i, line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// 	return (0);
// }