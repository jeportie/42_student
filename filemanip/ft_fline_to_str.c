/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fline_to_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:50:04 by jeportie          #+#    #+#             */
/*   Updated: 2023/11/12 18:11:09 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filemanip.h"

char	*ft_fline_to_str(int fd)
{
	static char fline_buf[FLINE_BUFFER_SIZE];
	int			bytes_read;
	size_t		i;
	char		*line;

	i = 0;
	if (fd < 0)
		return (NULL);

}
