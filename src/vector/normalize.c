/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 21:18:59 by cdahlhof          #+#    #+#             */
/*   Updated: 2024/03/10 21:54:10 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/**
 * @brief set the length of a vector to 1 unit
 * @param dimension amount of given additional values
 * @warning all following argunemts must be pointers to the values
*/
void	normalize(int dimension, ...)
{
	double	len = 0;

	va_list	coordinate;
	va_start(coordinate, dimension);
	for (int i = 0; i < dimension; i++)
	{
		double val = (double) *va_arg(coordinate, double *);
		len += pow(val, 2);
	}
	len = pow(len, 0.5);
	va_end(coordinate);

	if (len == 0)
		return ;
	va_list	pointers;
	va_start(pointers, dimension);

	for (int i = 0; i < dimension; i++)
	{
		double * ptr = va_arg(pointers, double *);
		*ptr = *ptr / len;
	}
}

// Note: most subjects do not explicitly allow variadic arguments

/**
 * @brief set the length of two dimensional vector to 1 unit
 * @warning all following argunemts must be pointers to the values
*/
void	normalize_2d(double *x, double *y)
{
	double len;

	if (len == 0)
		return ;
	len = veclen_2d(*x, *y);
	*x = *x / len;
	*y = *y / len;
}

/**
 * @brief set the length of three dimensional vector to 1 unit
 * @warning all following argunemts must be pointers to the values
*/
void	normalize_3d(double *x, double *y, double *z)
{
	double len;

	if (len == 0)
		return ;
	len = veclen_3d(*x, *y, *z);
	*x = *x / len;
	*y = *y / len;
	*z = *z / len;
}
