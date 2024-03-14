/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 21:12:53 by cdahlhof          #+#    #+#             */
/*   Updated: 2024/03/14 20:09:40 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/**
 * @brief return the length of a given vector
 * @param dimension amount of given additional values
*/
double	veclen(int dimension, ...)
{
	double	sum;
	double	val;
	va_list	coordinate;
	int		i;

	va_start(coordinate, dimension);
	sum = 0;
	i = 0;
	while (i < dimension)
	{
		val = va_arg(coordinate, double);
		sum += pow(val, 2);
		i++;
	}
	return (pow(sum, 0.5));
}

// Note: most subjects do not explicitly allow variadic arguments

/**
 * @brief return the length of a two dimensional vector
*/
double	veclen_2d(double x, double y)
{
	double	sum;

	sum = 0;
	sum = pow(x, 2);
	sum += pow(y, 2);
	return (pow(sum, 0.5));
}

/**
 * @brief return the length of a three dimensional vector
*/
double	veclen_3d(double x, double y, double z)
{
	double	sum;

	sum = 0;
	sum = pow(x, 2);
	sum += pow(y, 2);
	sum += pow(z, 2);
	return (pow(sum, 0.5));
}
