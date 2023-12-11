/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:37:04 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/10 18:45:37 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../function_libraries/libfmanip.h"
#include "../function_libraries/libft.h"

int	main(void)
{
	char	func_name[100];

	printf("Enter the function name :");
	scanf("%99s", func_name);
	ft_run_test(func_name);
	return (0);
}
