/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 13:04:10 by clems             #+#    #+#             */
/*   Updated: 2022/07/16 20:36:49 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// return a pointer to the first instance of c in the s, checking only n bytes
char	*ft_strrchr(const char *str, int c)
{
	size_t	i;
	char	*ptr;

	c = (unsigned char)c;
	ptr = NULL;
	i = 0;
	while (i <= ft_strlen(str))
	{
		if (str[i] == c)
		{
			ptr = (char *)str + i;
		}
		i++;
	}
	return (ptr);
}
//#include <stdio.h>
//int main()
//{
//	char	string[] = "hvbjnk,imho.im";
//	char	c = 'k';
//	printf("%s\t%c\n%s\n", string,  c, ft_strrchr(string, c));
//}
