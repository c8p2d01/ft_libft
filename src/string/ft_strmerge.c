/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:42:52 by cdahlhof          #+#    #+#             */
/*   Updated: 2026/03/30 13:31:29 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/**
 * @brief	merge two stings given as parameters into a new one, 
 * 			freeing the given ones 
 */
char	*ft_strmerge(char *s1, char *s2)
{
	size_t	l1;
	size_t	l2;
	char	*concat;
	size_t	i;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	concat = ft_malloc(l1 + l2 + 1);
	if (!concat)
		return(NULL);
	i = 0;
	while (i++ < l1)
		concat[i] = s1[i];
	while (i++ < l1 + l2)
		concat[i] = s2[i - l1];
	concat[i] = '\0';
	ft_free(s1);
	ft_free(s2);
	return (concat);
}
