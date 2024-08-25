/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:43:01 by cdahlhof          #+#    #+#             */
/*   Updated: 2023/01/02 18:57:10 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/**
 * @brief replace every instance of ind in base with add
 * @param base char* base string to search through
 * @param ind indicator to be replaced
 * @param add inserted string
 */
void	str_sed(char **base, char *ind, char *add)
{
	char	*scour;
	int		n;
	int		len[2];

	len[0] = ft_strlen(ind);
	len[1] = ft_strlen(add);
	scour = *base;
	n = -1;
	while (scour != 0)
	{
		scour = ft_strnstr(scour, ind, ft_strlen(scour));
		if (!scour)
			break ;
		scour += len[1];
		n++;
	}
	*base = ft_realloc(*base, ft_strlen(*base), n * (len[1] - len[0]));
	scour = *base;
	while (1)
	{
		scour = ft_strnstr(scour, ind, ft_strlen(scour));
		if (!scour)
			break ;
		ft_memmove(scour + len[1], scour + len[0], ft_strlen(scour));
		ft_memcpy(scour, add, len[1]);
		scour += len[1];
	}
}
