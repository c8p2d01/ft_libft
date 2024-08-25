/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:42:56 by cdahlhof          #+#    #+#             */
/*   Updated: 2024/03/27 21:05:42 by cdahlhof         ###   ########.fr       */
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

static	int	ft_set_strcount(char const *s, char *set)
{
	int		i;
	int		count;
	char	*str;

	i = 0;
	count = 1;
	str = ft_strtrim(s, set);
	while (str && str[i])
	{
		if (ft_strchr(set, str[i]) && str[i + 1] && !ft_strchr(set, str[i + 1]))
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

/**
 * Allocates ft_calloc and returns an array of strings obtained by
 * splitting ’s’ using the characters of ’set’ as a delimiter. The array must be
 * ended by a NULL pointer. Returns array of new strings resulting from the
 * split. NULL if the allocation fails.
 * @param s [char const *] char * to be split
 * @param set [char *] set of chars to be split by
 * @return [char **] split array
*/
char	**ft_set_split(char const *s, char *set)
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
	array = ft_calloc((ft_set_strcount(s, set) + 1), sizeof(char *));
	if (!array)
		return (0);
	while (s[pos2])
	{
		while (ft_strchr(set, s[pos2]) && s[pos2])
			pos2++;
		pos1 = pos2;
		while (!ft_strchr(set, s[pos2]) && s[pos2])
			pos2++;
		if (!ft_strchr(set, s[pos2 - 1]))
			array[count] = ft_substr(s, pos1, pos2 - pos1);
		count ++;
	}
	return (array);
}

// int main()
// {
// 	char input[] = "this is\ta string delimited\tby both spaces\t \t\tand tabs\t\t\t\t  lal   \t";
// 	char **result;

// 	result = ft_set_split(input, " \t");
// 	printf("split input\t%s\n", input);
// 	for(int i = 0; result[i]; i++)
// 	{
// 		printf("split element nr \t%i\t>%s<\n", i, result[i]);
// 	}
// }
