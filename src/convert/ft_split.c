/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:42:56 by cdahlhof          #+#    #+#             */
/*   Updated: 2023/01/02 21:12:04 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static	int	ft_strcount(char const *s, char c)
{
	int		i;
	int		count;
	char	*str;
	char	set[2];

	i = 0;
	count = 1;
	set[0] = c;
	set[1] = 0;
	str = ft_strtrim(s, set);
	while (str && str[i])
	{
		if (str[i] == c && str[i + 1] && str[i + 1] != c)
			count ++;
		i++;
	}
	free (str);
	return (count);
}

/**
 * Allocates ft_calloc and returns an array of strings obtained by
 * splitting ’s’ using the character ’c’ as a delimiter. The array must be
 * ended by a NULL pointer. Returns array of new strings resulting from the
 * split. NULL if the allocation fails.
 * @param s [char const *] char * to be split
 * @param c [char] char to be split by
 * @return [char **] split array
*/
char	**ft_split(char const *s, char c)
{
	char	**array;
	int		count;
	int		pos1;
	int		pos2;

	if (!s)
		return (NULL);
	count = 0;
	pos1 = 0;
	pos2 = 0;
	array = ft_calloc((ft_strcount(s, c) + 1), sizeof(char *));
	if (!array)
		return (0);
	while (s[pos2])
	{
		while (s[pos2] == c && s[pos2])
			pos2++;
		pos1 = pos2;
		while (s[pos2] != c && s[pos2])
			pos2++;
		if (s[pos2 - 1] != c)
			array[count] = ft_substr(s, pos1, pos2 - pos1);
		count ++;
	}
	return (array);
}
