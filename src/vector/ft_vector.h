#ifndef VECTOR_H
# define VECTOR_H

# include "../../inc/libft.h"

# ifndef PI
#  define PI 3.14159265359
# endif

typedef struct vec2d_s {
	double	x;
	double	y;
} vec2d_t;

typedef struct vec3d_s {
	double	x;
	double	y;
	double	z;
} vec3d_t;

double	veclen(int dimension, ...);
double	veclen_2d(double x, double y);
double	veclen_3d(double x, double y, double z);
double	veclen2d(vec2d_t *vector);
double	veclen3d(vec3d_t *vector);

void	normalise(int dimension, ...);
void	normalise_2d(double *x, double *y);
void	normalise_3d(double *x, double *y, double *z);
void	normalise2d(vec2d_t *vector);
void	normalise3d(vec3d_t *vector);

void	resize2d(vec2d_t *vector, double size);
void	resize3d(vec3d_t *vector, double size);

vec2d_t	rotate2d(vec2d_t *vector, double degree);

#endif