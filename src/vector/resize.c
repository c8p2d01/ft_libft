#include "ft_vector.h"

/**
 * @brief set the length of a vector
 * @param dimension amount of given additional values
 * @param size second argument will be interpreted as the size
 * @warning all following argunemts must be pointers to the values
*/
void	resize(int dimension, ...)
{
	double	len[2];
	double	*val;
	double	size;
	va_list	coordinate;
	int		i;

	va_start(coordinate, dimension);
	size = (double) *va_arg(coordinate, double *);
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
	size = (double) *va_arg(coordinate, double *);
	i = 0;
	while (i++ < dimension)
	{
		val = va_arg(coordinate, double *);
		*val = (*val / len[0]) * size;
	}
}

/**
 * @brief set the length of two dimensional vector
 * @param size the size the vecto will be set to
 * @warning all following argunemts must be pointers to the values
*/
void	resize_2d(double *x, double *y, double size)
{
	double	len;

	len = veclen_2d(*x, *y);
	if (len == 0)
		return ;
	*x = (*x / len) * size;
	*y = (*y / len) * size;
}

/**
 * @brief set the length of three dimensional vector
 * @param size the size the vecto will be set to
 * @warning all following argunemts must be pointers to the values
*/
void	resize_3d(double *x, double *y, double *z, double size)
{
	double	len;

	len = veclen_3d(*x, *y, *z);
	if (len == 0)
		return ;
	*x = (*x / len) * size;
	*y = (*y / len) * size;
	*z = (*z / len) * size;
}

/**
 * set the length of a 2 dimensional vector
 */
void	resize2d(vec2d_t *vector, double size)
{
	normalise2d(vector);
	vector->x = vector->x * size;
	vector->y = vector->y * size;
}


/**
 * set the length of a 3 dimensional vector
 */
void	resize3d(vec3d_t *vector, double size)
{
	normalise3d(vector);
	vector->x = vector->x * size;
	vector->y = vector->y * size;
	vector->z = vector->z * size;
}