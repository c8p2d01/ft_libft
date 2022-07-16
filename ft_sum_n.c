/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sum_n.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:54:36 by cdahlhof          #+#    #+#             */
/*   Updated: 2022/07/16 20:36:43 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_sum_n(size_t n)
{
	size_t	res;

	res = 0;
	if (n > 0)
		res = res + n + ft_sum_n(n - 1);
	return (res);
}

// int main()
// {
// 	int nbr = 5;
// 	printf("number :\t%d\nresult :\t%d", nbr, (int)ft_sum_n(nbr));
// }
