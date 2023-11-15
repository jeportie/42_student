/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:35:30 by jeportie          #+#    #+#             */
/*   Updated: 2023/11/15 23:24:27 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	dst_len = 0;
	while (dst[dst_len] && dst_len < size)
		dst_len++;
	src_len = ft_strlen(src);
	if (!size || dst_len == size)
		return (dst_len + src_len);
	i = 0;
	while (src[i] && dst_len + i < size -1)
	{
		dst[dst_len + 1] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

/*
Let's break down the behavior of ft_strlcat with a visual example for clarity.

	- The function calculates the length of dst and src.

	- It checks if dstsize is 0 or if dst is already full (dst_len == dstsize),
	in which case it returns the total length dst would have after 
	concatenation.

	- It then appends characters from src to dst, being careful not to write 
	more characters than dstsize - 1.

	 -It always null-terminates dst, provided dstsize is not 0.

	 - Finally, it returns the total length of the string it tried to create, 
	 which is the sum of the lengths of dst and src.

The strlcat function concatenates strings with the same input parameters as 
strncat, but unlike strncat, it takes the full size of the buffer 
(not just the length) and guarantees to NUL-terminate the result 
(as long as there is at least one byte free in dst). 
Importantly, ft_strlcat do not overflow the destination buffer.

Here's the key point:

	- ft_strlcat will append at most dstsize - strlen(dst) - 1 characters from 
	src to dst.

This means that it will append characters from src to the end of dst, but it
will stop appending either when it has added dstsize - strlen(dst) - 1 
characters, or when it reaches the end of src, whichever comes first. 
The -1 is to leave space for the null terminator.

Example:

Let's say we have a destination string dst and a source string src:

	- dst = "Hello"

	- src = "World"

	- dstsize = 10 (the total size of the dst buffer)

Initial state of dst buffer: ["H", "e", "l", "l", "o", "\0", "?", "?", "?", "?"]
(where "?" represents uninitialized space).

Now, let's apply ft_strlcat:

	- The length of dst (strlen(dst)) is 5.

	- The maximum number of characters to append is dstsize - strlen(dst) - 1 =
	10 - 5 - 1 = 4.

	- So, ft_strlcat will append at most 4 characters from src to dst.

After ft_strlcat:

	- dst = "HelloWorl"

	- Final state of dst buffer: 
	  ["H", "e", "l", "l", "o", "W", "o", "r", "l", "\0"].

Notice that only 4 characters from src were appended to dst, and the result was 
null-terminated.

Conclusion:

	- The function ensures that dst is null-terminated after appending 
	characters from src.

	- It appends characters based on the available space in dst, accounting for
	its current length and the total buffer size (dstsize).

	- It returns the total length of the string it tried to create, not the 
	length of the string actually created. In the example, it would return 9 
	(length of "Hello" + length of "World"), even though it only appended part 
	of "World" due to size constraints.
*/
