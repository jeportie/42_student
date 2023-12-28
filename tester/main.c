/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:37:04 by jeportie          #+#    #+#             */
/*   Updated: 2023/12/28 12:48:14 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libfmanip.h"
#include "lib/libft.h"
#include "src/libftest.h"
#include <string.h>

int	main(void)
{
	char	func_name[100];

	while (1)
	{
		printf("Enter the function name :\n(Enter 'exit' to quit.)\n");
		scanf("%99s", func_name);
		if (!strcmp(func_name, "exit"))
			break;
		ft_run_test(func_name);		
	}
	return (0);
}
