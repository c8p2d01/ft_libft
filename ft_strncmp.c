/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:35:12 by clems             #+#    #+#             */
/*   Updated: 2022/07/16 20:37:19 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	compare the given inputs byte by byte returning 0 if they equal, and a 
//	number depending on which of them has a first instance that respectively
//	is bigger or less than the other
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (n - i > 0 && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i ++;
	}
	return (0);
}
//#include <stdio.h>
//int	main()
//{
//	char	satz1[50] = "running out of things to\0 writhdjvfumhbe part 2";
//	char	satz2[50] = "running out of things to\0 write part 2";
//	int i = ft_strncmp(satz1, satz2, 37);
//	printf("%s\n%s\n%d\n", satz1, satz2, i);
//}
