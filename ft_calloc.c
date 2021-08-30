/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clems <clems@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 13:34:13 by clems             #+#    #+#             */
/*   Updated: 2021/06/01 09:46:11 by clems            ###   ########.fr       */
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

	dest = malloc(nmemb * n);
	if (!dest)
		return (0);
	ft_bzero(dest, nmemb * n);
	return (dest);
}
