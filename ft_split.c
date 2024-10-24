/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:42:56 by cdahlhof          #+#    #+#             */
/*   Updated: 2024/10/24 18:11:41 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_2dstr(char **s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		free(s[i]);
		i ++;
	}
	free(s);
}

// counts words in a string and returns
static	int	ft_strcount(char const *s, char c, int *pos1, int *pos2)
{
	int	i;
	int	count;

	*pos1 = 0;
	*pos2 = 0;
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && !(count % 2))
			count++;
		if (s[i] == c && (count % 2))
			count++;
		i++;
	}
	count++;
	return ((count / 2));
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
	int		count[2];
	int		pos[2];

	if (!s)
		return (NULL);
	count[0] = 0;
	count[1] = ft_strcount(s, c, &pos[0], &pos[1]);
	array = ft_calloc(count[1] + 1, sizeof(char *));
	if (!array)
		return (NULL);
	while (count[0] < count[1])
	{
		while (s[pos[1]] && s[pos[1]] == c)
			pos[1]++;
		pos[0] = pos[1];
		while (s[pos[1]] && s[pos[1]] != c)
			pos[1]++;
		if (s[pos[1] - 1] != c)
			array[count[0]] = ft_substr(s, pos[0], pos[1] - pos[0]);
		if (!array[count[0]])
			return (free_2dstr(array), NULL);
		count[0]++;
	}
	return (array);
}
