#include "ft_vector.h"

vec2d_t		rotate2d(vec2d_t *vector, double degree)
{
	vec2d_t	result;
	double	rad;
	
	rad = degree * PI / 180;
	result.x = vector->x * cos(rad) - vector->y * sin(rad);
	result.y = vector->x * sin(rad) + vector->y * cos(rad);
	//normalise2d(&result);
	return (result);
}
