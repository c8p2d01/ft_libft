/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:36:09 by clems             #+#    #+#             */
/*   Updated: 2022/07/16 20:38:55 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// count the number of digits in the given number b of basis(length) a
size_t	ft_log(size_t b, int a)
{
	int	exp;

	exp = 1;
	while (b / a)
	{
		exp++;
		b /= a;
	}
	return (exp);
}
