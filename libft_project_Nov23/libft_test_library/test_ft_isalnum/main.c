/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:37:04 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/09 16:40:19 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../function_libraries/libfmanip.h"
#include "../function_libraries/libft.h"

static void ft_strtoupper(char *str) {
    if (!str) return;
    while (*str) {
        *str = ft_toupper((unsigned char)*str);
        str++;
    }
}

static int	ft_run_test(const char *func_name)
{
	char	upper_name[100];
	char	test_file_name[120];
	t_tstlst	*lst;
	int	i;

	ft_strlcpy(upper_name, func_name, sizeof(func_name));
	ft_strtoupper(upper_name);
	sprintf(test_file_name, "ft_%s_test_data.txt", func_name);

	lst = ft_load_tests(test_file_name);
	if (!lst)
		exit(EXIT_FAILURE);
	i = 1;
	printf("FT_%s TEST:\n", upper_name);
	while (lst)
	{
        ft_test_function(lst, ft_call_ft(func_name, LIBC), ft_call_ft(func_name, LIBFT), ARG_INT);
		i++;
		lst = lst->next;
	}
	return (0);
}

int	main(void)
{
	char	func_name[100];

	printf("Enter the function name :");
	scanf("%99s", func_name);
	ft_run_test(func_name);
	return (0);
}
