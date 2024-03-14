/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatSpaces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:42:56 by cdahlhof          #+#    #+#             */
/*   Updated: 2024/03/14 23:23:27 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static int	trimmedlength(char const *s)
{
	int	len;
	int	count;

	count = 0;
	len = 0;
	while (s[len])
	{
		while (ft_strchr("\t\n\v\f\r ", s[len]))
			len++;
		while (!ft_strchr("\t\n\v\f\r ", s[len]))
		{
			count++;
			len++;
		}
		count++;
	}
	return (count);
}

/**
 * trim spaces between words down to one
 * @param s [char const *] char * to be split
 * @return [char *] shortet array
*/
char	*ft_formatSpaces(char const *s)
{
	char	*array;
	int		cpyfrom;
	int		cpyto;

	if (!s)
		return (NULL);
	array = ft_calloc(trimmedlength(s), sizeof(char));
	cpyfrom = 0;
	cpyto = 0;
	while (s[cpyfrom])
	{
		while (ft_strchr("\t\n\v\f\r ", s[cpyfrom]))
			cpyfrom++;
		while (!ft_strchr("\t\n\v\f\r ", s[cpyfrom]))
		{
			array[cpyto] = s[cpyfrom];
			cpyfrom++;
			cpyto++;
		}
		array[cpyto] = s[cpyfrom];
	}
	return (array);
}
