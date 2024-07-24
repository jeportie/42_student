/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:22:36 by neleon            #+#    #+#             */
/*   Updated: 2023/12/05 16:07:44 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	void	*ptr;

	if (size == 0 || nmemb == 0)
		return (malloc(0));
	if (nmemb > 2147483647 / size)
		return (NULL);
	total = nmemb * size;
	ptr = (void *)malloc(total);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}

// int main() {
//     size_t count = 5;
//     size_t size = sizeof(int);

//     // Test 1 : Allocation normale
//     int *arr1 = (int *)ft_calloc(count, size);
//     int *arr2 = (int *)calloc(count, size);

//     if (ft_memcmp(arr1, arr2, count * size) != 0) {
//         printf("Test 1 : FAIL\n");
//     } else {
//         printf("Test 1 : OK\n");
//     }

//     free(arr1);
//     free(arr2);

//     // Test 2 : Allocation avec count 0
//     arr1 = (int *)ft_calloc(0, size);
//     arr2 = (int *)calloc(0, size);

//     if ((arr1 == NULL && arr2 != NULL) || (arr1 != NULL && arr2 == NULL)) {
//         printf("Test 2 : FAIL\n");
//     } else {
//         printf("Test 2 : OK\n");
//     }

//     free(arr1);
//     free(arr2);

//     // Test 3 : Allocation avec size 0
//     arr1 = (int *)ft_calloc(count, 0);
//     arr2 = (int *)calloc(count, 0);

//     if ((arr1 == NULL && arr2 != NULL) || (arr1 != NULL && arr2 == NULL)) {
//         printf("Test 3 : FAIL\n");
//     } else {
//         printf("Test 3 : OK\n");
//     }

//     free(arr1);
//     free(arr2);

//     return (0);
// }
