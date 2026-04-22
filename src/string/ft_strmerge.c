/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:42:52 by cdahlhof          #+#    #+#             */
/*   Updated: 2026/03/30 13:38:10 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/**
 * @brief	merge two stings given as parameters into a new one, 
 * 			freeing the given ones 
 */
char	*ft_strmerge(char *s1, char *s2)
{
	size_t	l1;
	size_t	l2;
	char	*concat;
	size_t	i;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	concat = ft_malloc(l1 + l2 + 1);
	if (!concat)
		return(NULL);
	i = 0;
	while (i < l1)
	{
		concat[i] = s1[i];
		i++;
	}
	while (i < l1 + l2)
	{
		concat[i] = s2[i - l1];
		i++;
	}
	concat[i] = '\0';
	ft_free(s1);
	ft_free(s2);
	return (concat);
}

char	*ft_strsmerge(size_t n, ...)
{
	va_list	s;
	size_t	i;
	size_t	in;
	char	*res;
	char	*tmp;

	i = 0;
	in = 0;
	va_start(s, n);
	while (in++ < n)
		i += ft_strlen(va_arg(s, char *));
	va_end(s);
	res = ft_calloc(i + 1, sizeof(char));
	va_start(s, n);
	in = 0;
	while (in++ < n)
	{
		tmp = va_arg(s, char *);
		if (!tmp)
			continue ;
		ft_strlcat(&res[ft_strlen(res)], tmp, ft_strlen(tmp) + 1);
	}
	return (res);
}

// int main(){
// 	char *a = "hell";
// 	char *b = "o wor";
// 	char *c = NULL;

// 	char *m = ft_strsmerge(3, a, b, c);
// 	printf("%s\n", m);
// }
