/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 13:41:50 by clems             #+#    #+#             */
/*   Updated: 2021/08/25 01:32:41 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//count the number of sequential delimeters
static int	ft_skipc(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] == c && str[i])
		i++;
	return (i);
}

//count the number of true delimeters (multiple in a row count as one)
static int	ft_word_count(const char *str, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	if (str[i] && str[i] != c)
		n++;
	while (str[i])
	{
		if (str[i] == c)
		{
			while (str[i] == c)
				i++;
			if (str[i] && str[i] != c)
				n++;
		}
		else
			i++;
	}
	return (n);
}

// in case the allocation fails after a few word have been allocated,
// this void frees the entire array and the array itself
static void	ft_free2d(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

// copy the first word into the result and overwrite the word with the
// remainding sentence
static char	*ft_strmv(char *str, char c)
{
	int		i;
	int		s;
	char	*res;

	i = 0;
	s = ft_skipc(str, c);
	while (str[s + i] != c && str[i])
	{
		i++;
	}
	res = ft_calloc(i + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (str[s + i] != c && str[s + i])
	{
		res[i] = str[s + i];
		i++;
	}
	if (str[i + s])
		ft_strlcpy(&str[0], &str[i + s], ft_strlen(str) + 1);
	else
		ft_bzero(str, ft_strlen(str) + 1);
	return (res);
}

// create the result array, calloc it and call the other functions
//	Comment: in this function I first count the number of valid words(mulitple
//	delimiters cout as one) then i allocate memory towards at copy if the whole
//	Input, to later perform conversions into single words on it
//	freeinh that string tho is one line too many which is why i had to compress
//	the wordcounter and the coutning var (used later on) into one int[],
//	which leads to a less readable code: i[0] is the number of words,
//	i[1] is the counter 
char	**ft_split(const char *str, char c)
{
	int		i[2];
	char	**res;
	char	*pstr;

	if (!str)
		return (NULL);
	i[0] = ft_word_count(str, c) + 1;
	res = ft_calloc(i[0] + 1, sizeof(char *));
	pstr = ft_calloc(ft_strlen((char *)str) + 1, sizeof(char));
	if ((!pstr) || (!res))
		return (NULL);
	ft_strlcpy(pstr, str, ft_strlen((char *)str) + 1);
	i[1] = 0;
	while (i[1] < i[0] - 1)
	{
		res[i[1]] = ft_strmv(pstr, c);
		if (!res)
		{
			ft_free2d(res);
			return (NULL);
		}
		i[1]++;
	}
	free(pstr);
	return (res);
}
// #include <stdio.h>
// int main(void)
// {
// 	int i = 0;
// 	char c = ' ';
// 	char s[100] = "        a            c       b                            ";
// 	char **r = ft_split(NULL, c);
// 	while (r[i])
// 	{
// 		printf("%d\t%d\t%p\t%s\n",i, (int)ft_strlen(r[i]), r[i], r[i]);
// 		i++;
// 	}
// }
