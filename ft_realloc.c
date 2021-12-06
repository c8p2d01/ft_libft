/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:07:00 by cdahlhof          #+#    #+#             */
/*   Updated: 2021/12/06 08:43:38 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *old, size_t ol, size_t add)
{
	char	*new;

	new = ft_calloc(ol + add, 1);
	ft_memcpy(new, old, ol);
	free(old);
	return ((void *)new);
}
