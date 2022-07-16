/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:11:01 by clems             #+#    #+#             */
/*   Updated: 2022/07/16 20:37:43 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// create a duplicate string of s
char	*ft_strdup(const char *s)
{
	char	*dest;

	dest = ft_calloc(ft_strlen((char *)s) + 1, 1);
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, s, ft_strlen((char *)s) + 1);
	return (dest);
}
//#include <stdio.h>
//int main()
//{
//	char	source[] = "szduf8kbn, ml";
//	char	*dest = malloc(100 * sizeof(char));
//	dest	=	ft_strdup(source);
//	printf("%s\n%s\n", source, dest);
//}
