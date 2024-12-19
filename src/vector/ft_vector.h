/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 02:33:58 by cdahlhof          #+#    #+#             */
/*   Updated: 2024/12/19 21:27:12 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include "../../inc/libft.h"

# ifndef PI
#  define PI 3.14159265359
# endif

typedef struct s_vec2d
{
	double	x;
	double	y;
}	t_vec2d;

typedef struct s_vec3d
{
	double	x;
	double	y;
	double	z;
}	t_vec3d;

double	veclen(int dimension, ...);
double	veclen_2d(double x, double y);
double	veclen_3d(double x, double y, double z);
double	veclen2d(t_vec2d *vector);
double	veclen3d(t_vec3d *vector);

void	normalise(int dimension, ...);
void	normalise_2d(double *x, double *y);
void	normalise_3d(double *x, double *y, double *z);
void	normalise2d(t_vec2d *vector);
void	normalise3d(t_vec3d *vector);

void	resize2d(t_vec2d *vector, double size);
void	resize3d(t_vec3d *vector, double size);

t_vec2d	rotate2d(t_vec2d *vector, double degree);

double	angle2d(t_vec2d a, t_vec2d b);
double	angle3d(t_vec3d a, t_vec3d b);

#endif