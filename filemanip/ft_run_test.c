/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:45:03 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/12 17:44:58 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfmanip.h"

int	ft_run_test(const char *func_name)
{
	char		upper_name[100];
	char		test_file_name[120];
	t_tstlst	*lst;
	t_arg		*args;

	ft_strlcpy(upper_name, func_name, sizeof(func_name));
	ft_strtoupper(upper_name);
	sprintf(test_file_name, "ft_%s_test_data.txt", func_name);
	args = ft_find_ftparam_type(func_name);
	lst = ft_load_tests(test_file_name);
	if (!lst)
		exit(EXIT_FAILURE);
	printf("FT_%s TEST:\n", upper_name);
	if (ft_find_ftreturn_type(func_name) == RETURN_INT)
	{
		while (lst)
		{
			if (args[0] == ARG_INT && !args[1])
		        ft_inttest_for_int(ft_call_func_int(func_name, LIBC), ft_call_func_int(func_name, LIBFT), lst);
			if (args[0] == ARG_STRING && !args[1])
		        ft_inttest_for_str(ft_call_func_int(func_name, LIBC), ft_call_func_int(func_name, LIBFT), lst);
			if (args[0] == ARG_CONST_VOID && args[1] == ARG_CONST_VOID && args[2] == ARG_SIZE_T)
				ft_inttest_for_vvz(ft_call_func_int(func_name, LIBC), ft_call_func_int(func_name, LIBFT), lst);
			if (args[0] == ARG_CONST_STRING && args[1] == ARG_CONST_STRING && args[2] == ARG_SIZE_T)
				ft_inttest_for_ssz(ft_call_func_int(func_name, LIBC), ft_call_func_int(func_name, LIBFT), lst);
			lst = lst->next;
		}
	}
	else if (ft_find_ftreturn_type(func_name) == RETURN_STR)
	{
		while (lst)
		{
			if (args[0] == ARG_STRING && !args[1])
		        ft_chartest_for_str(ft_call_func_str(func_name, LIBC), ft_call_func_str(func_name, LIBFT), lst);
			if (args[0] == ARG_CONST_STRING && args[1] == ARG_INT)
		        ft_chartest_for_si(ft_call_func_str(func_name, LIBC), ft_call_func_str(func_name, LIBFT), lst);
			if (args[0] == ARG_CONST_STRING && args[1] == ARG_CONST_STRING && args[2] == ARG_SIZE_T)
				ft_chartest_for_ssz(ft_call_func_str(func_name, LIBC), ft_call_func_str(func_name, LIBFT), lst);
			lst = lst->next;
		}
	}
	return (0);
}
