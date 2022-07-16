/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:07:00 by cdahlhof          #+#    #+#             */
/*   Updated: 2022/07/16 20:37:50 by cdahlhof         ###   ########.fr       */
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
