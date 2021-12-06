/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:11:52 by cdahlhof          #+#    #+#             */
/*   Updated: 2021/12/03 01:48:47 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_power(size_t base, size_t exponent)
{
	size_t	res;

	res = 1;
	while (exponent-- > 0)
		res = res * base;
	return (res);
}

// int main()
// {
// 	int nbr = 2;
// 	printf("number :\t%d\nresult :\t%d", nbr, (int)ft_power_of(nbr, 10));
// }
