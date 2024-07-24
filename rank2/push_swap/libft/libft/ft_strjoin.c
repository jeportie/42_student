/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:36:29 by neleon            #+#    #+#             */
/*   Updated: 2024/05/23 20:28:05 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	len_s1;
	size_t	len_s2;

	if (!s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	join = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!join)
		return (NULL);
	ft_strlcpy(join, s1, (len_s1 + 1));
	ft_strlcat(join, s2, len_s1 + len_s2 + 1);
	return (join);
}
// int main() {
//     char const *s1;
//     char const *s2;
//     char *result;

//     // Test 1: Concaténation de deux chaînes normales
//     s1 = "Hello, ";
//     s2 = "World!";
//     result = ft_strjoin(s1, s2);
//     printf("Test 1: %s\n", result);
//     free(result);

//     // Test 2: Concaténation avec une chaîne vide
//     s1 = "";
//     s2 = "World!";
//     result = ft_strjoin(s1, s2);
//     printf("Test 2: %s\n", result);
//     free(result);

//     // Test 3: Concaténation de deux chaînes vides
//     s1 = "";
//     s2 = "";
//     result = ft_strjoin(s1, s2);
//     printf("Test 3: %s\n", result);
//     free(result);

//     // Test 4: Premier pointeur nul
//     s1 = NULL;
//     s2 = "World!";
//     result = ft_strjoin(s1, s2);
//     printf("Test 4: %s\n", result ? result : "NULL");

//     // Test 5: Second pointeur nul
//     s1 = "Hello, ";
//     s2 = NULL;
//     result = ft_strjoin(s1, s2);
//     printf("Test 5: %s\n", result ? result : "NULL");

//     return (0);
// }
