/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:14:04 by clems             #+#    #+#             */
/*   Updated: 2022/07/16 20:36:45 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (i >= len)
		str = ft_calloc((len + 1), sizeof(*s));
	else
		str = ft_calloc((i + 1), sizeof(*s));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (*(s + i) != '\0')
	{
		if (i >= start && j < len)
		{
			*(str + j) = *(s + i);
			j++;
		}
		i++;
	}
	return (str);
}

// #include <stdio.h>
// int main()
// {
// 	char	str[] = "123456789123456";
// 	printf("%s\t%s\n", str, ft_substr(str, 10, 1));
// }
