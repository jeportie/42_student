/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 01:01:16 by jeportie          #+#    #+#             */
/*   Updated: 2024/01/05 02:34:49 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_apply_precision(t_format_spec spec, char **formatted_content)
{
    int		len;
    char	*new_str;
    int		total_len;
    int		copy_start;
    int		is_negative;

    is_negative = 0;
    if ((*formatted_content)[0] == '-')
        is_negative = 1;
    len = ft_strlen(*formatted_content) - is_negative;
    if (spec.precision <= len && spec.precision != -1)
        return;
    if (is_negative)
        total_len = spec.precision + 1;
    else
        total_len = spec.precision;
    new_str = (char *)malloc(sizeof(char) * (total_len + 1));
    if (!new_str)
    {
        spec.error = ERNOMEM;
        return ;
    }
    ft_memset(new_str, '0', total_len);
    if (is_negative)
        new_str[0] = '-';
    copy_start = total_len - len;
    ft_strlcpy(new_str + copy_start, *formatted_content + is_negative, len + 1);
    free(*formatted_content);
    *formatted_content = new_str;
}

