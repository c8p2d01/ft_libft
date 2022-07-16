/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:15:22 by clems             #+#    #+#             */
/*   Updated: 2022/07/16 20:36:47 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// return a string tha got his head and tail trimmed of 
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] != '\0' && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	str = ft_calloc(sizeof(*s1), (end - start +1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
	{
		str[i] = s1[start];
		start++;
		i++;
	}
	return (str);
}
//#include <stdio.h>
//int main()
//{
//	char	str[] = "3456inmmih,456789, fmkunk, l3456";
//	char	set[] = "1234567890";
//	printf("%s\t%s\n%s\n", str, set, ft_strtrim(str, set));
//}
