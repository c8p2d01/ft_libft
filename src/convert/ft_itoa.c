/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:41:45 by cdahlhof          #+#    #+#             */
/*   Updated: 2023/01/02 15:14:54 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static int	ft_digits(int n)
{
	int	digits;

	digits = 0;
	if (n <= 0)
		digits++;
	while (n)
	{
		digits++;
		n = n / 10;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	int		digits;
	char	*dest;
	long	nlong;

	digits = ft_digits(n);
	dest = ft_malloc(sizeof(char) * digits + 1);
	nlong = n;
	if (!dest)
		return (NULL);
	if (nlong < 0)
	{
		dest[0] = '-';
		nlong *= -1;
	}
	if (n == 0)
		dest[0] = '0';
	dest[digits] = '\0';
	digits--;
	while (nlong)
	{
		dest[digits] = nlong % 10 + '0';
		digits--;
		nlong = nlong / 10;
	}
	return (dest);
}
