/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 21:18:59 by cdahlhof          #+#    #+#             */
/*   Updated: 2024/03/14 21:14:18 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"


/**
 * @brief set the length of a vector to 1 unit
 * @param dimension amount of given additional values
 * @warning all following argunemts must be pointers to the values
*/
void	normalise(int dimension, ...)
{
	double	len[2];
	double	*val;
	va_list	coordinate;
	int		i;

	va_start(coordinate, dimension);
	i = 0;
	while (i++ < dimension)
	{
		len[1] = (double) *va_arg(coordinate, double *);
		len[0] += pow(len[1], 2);
	}
	len[0] = pow(len[0], 0.5);
	va_end(coordinate);
	if (len[0] == 0)
		return ;
	va_start(coordinate, dimension);
	i = 0;
	while (i++ < dimension)
	{
		val = va_arg(coordinate, double *);
		*val = *val / len[0];
	}
}

// Note: most subjects do not explicitly allow variadic arguments

/**
 * @brief set the length of two dimensional vector to 1 unit
 * @warning all following argunemts must be pointers to the values
*/
void	normalise_2d(double *x, double *y)
{
	double	len;

	len = veclen_2d(*x, *y);
	if (len == 0)
		return ;
	*x = *x / len;
	*y = *y / len;
}

/**
 * @brief set the length of three dimensional vector to 1 unit
 * @warning all following argunemts must be pointers to the values
*/
void	normalise_3d(double *x, double *y, double *z)
{
	double	len;

	len = veclen_3d(*x, *y, *z);
	if (len == 0)
		return ;
	*x = *x / len;
	*y = *y / len;
	*z = *z / len;
}

/**
 * @brief set the length of two dimensional vector to 1 unit
*/
void	normalise2d(vec2d_t *vector)
{
	double	len;

	len = veclen2d(vector);
	if (len == 0)
		return ;
	vector->x = vector->x / len;
	vector->y = vector->y / len;
}

/**
 * @brief set the length of three dimensional vector to 1 unit
*/
void	normalise3d(vec3d_t *vector)
{
	double	len;

	len = veclen3d(vector);
	if (len == 0)
		return ;
	vector->x = vector->x / len;
	vector->y = vector->y / len;
	vector->z = vector->z / len;
}
