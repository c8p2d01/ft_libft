/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:42:52 by cdahlhof          #+#    #+#             */
/*   Updated: 2024/03/27 09:02:47 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*ft_realloc(void *old, size_t old_len, size_t add_len)
{
	char	*new;

	new = ft_calloc(old_len + add_len, 1);
	ft_memcpy(new, old, old_len);
	if (old)
		free(old);
	return ((void *)new);
}
