/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   veclen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 21:12:53 by cdahlhof          #+#    #+#             */
/*   Updated: 2024/09/09 02:53:42 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

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

/**
 * @brief return the length of a two dimensional vector
*/
double	veclen2d(t_vec2d *vector)
{
	double	sum;

	sum = 0;
	sum = pow(vector->x, 2);
	sum += pow(vector->y, 2);
	return (pow(sum, 0.5));
}

/**
 * @brief return the length of a two dimensional vector
*/
double	veclen3d(t_vec3d *vector)
{
	double	sum;

	sum = 0;
	sum = pow(vector->x, 2);
	sum += pow(vector->y, 2);
	sum += pow(vector->z, 2);
	return (pow(sum, 0.5));
}
