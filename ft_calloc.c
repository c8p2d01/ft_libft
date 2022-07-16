/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 13:34:13 by clems             #+#    #+#             */
/*   Updated: 2022/07/16 20:39:24 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// allocate memory that consists only of '\0' bytes
//	if (!nb || !size || nmemb * n > sizeof(int))
//		return (NULL);
//		↑ cases which are in the manual but molinette failed me for some reason
void	*ft_calloc(size_t nmemb, size_t n)
{
	void	*dest;

	if (nmemb >= SIZE_MAX && n > 1)
		return (NULL);
	dest = malloc(nmemb * n);
	if (!dest)
		return (0);
	ft_bzero(dest, nmemb * n);
	return (dest);
}
