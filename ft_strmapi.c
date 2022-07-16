/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 18:06:17 by clems             #+#    #+#             */
/*   Updated: 2022/07/16 20:37:24 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// apply a given function to every char of s
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		i;

	res = ft_calloc(ft_strlen((char *)s) + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	return (res);
}
//char	testfunction(unsigned int i,char c)
//{
//	unsigned int	j;
//
//	j = 0;
//	while (j < i)
//	{
//		j++;
//		c++;
//	}
//	return (c);
//}
//#include <stdio.h>
//int main(void)
//{
//	char	str[8] = "1234567";
//	char	*res = ft_strmapi(str, testfunction);
//	printf("%s\n", res);
//}
