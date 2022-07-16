/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 19:15:46 by clems             #+#    #+#             */
/*   Updated: 2022/07/16 20:38:12 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// set n bytes of src to the value of c
void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)str)[i] = c;
		i++;
	}
	return (str);
}
//#include <stdio.h>
//int main()
//{
//	char	*destination;
//	destination = malloc(100 * sizeof(char));
//	ft_memset(destination, '4', 100);
//	printf("%s\n", destination);
//	ft_memset(destination, '2', 100);
//	printf("%s\n", destination);
//}
