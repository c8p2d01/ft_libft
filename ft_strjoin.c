/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:43:04 by cdahlhof          #+#    #+#             */
/*   Updated: 2024/10/20 03:11:22 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*dest;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	dest = ft_calloc(sizeof(char), (len1 + len2 + 1));
	if (!dest)
		return (NULL);
	ft_memcpy(dest, s1, len1);
	ft_memcpy(&dest[len1], s2, len2);
	dest[len1 + len2] = '\0';
	return (dest);
}
