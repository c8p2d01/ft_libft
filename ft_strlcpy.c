/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 13:46:26 by clems             #+#    #+#             */
/*   Updated: 2022/07/16 20:37:31 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// copy size bytes from src to dest, overwriting dest
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] && (i + 1) < size)
	{
		if (!(size == 0))
			dst[i] = src[i];
		i++;
	}
	if (!(size == 0))
		dst[i] = '\0';
	return (ft_strlen((char *)src));
}
//#include <stdio.h>
//int main()
//{
//	char	source[] = "szduf8kbn, ml";
//	char	*dest = malloc(100 * sizeof(char));
//	ft_strlcpy(dest, source, 7);
//	printf("%s\n%s\n", source, dest);
//}
