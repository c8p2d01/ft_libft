/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 12:15:06 by clems             #+#    #+#             */
/*   Updated: 2022/07/16 20:38:25 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// copy n bytes from src to dest, stopping at c
void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
		if (((unsigned char *)src)[i - 1] == (unsigned char)c)
			return (dest + i);
	}
	return (NULL);
}
//int main()
//{
//	char	*destination[20] = "00000000000000000000";
//	char	*source[] = "\\(^_^)/";
//	ft_memccpy(destination, source, '^', 10);
//	for(int i = 0; i < 20; i++)
//		write(1, &destination[i], 1);
//}
