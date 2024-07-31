/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_limit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:43:42 by cdahlhof          #+#    #+#             */
/*   Updated: 2023/01/02 15:14:54 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	i_limit(int *num, int low, int high)
{
	if (*num < low)
		*num = low;
	else if (*num > high)
		*num = high;
}

void	f_limit(float *num, float low, float high)
{
	if (*num < low)
		*num = low;
	else if (*num > high)
		*num = high;
}

void	lf_limit(double *num, double low, double high)
{
	if (*num < low)
		*num = low;
	else if (*num > high)
		*num = high;
}
