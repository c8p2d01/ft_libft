#include "ft_vector.h"

double	angle2d(vec2d_t a, vec2d_t b)
{
	return (((a.x * b.x) + (a.y * b.y)) \
			/
			(vec_len2d(&a) * vec_len2d(&b)))
}

double	angle3d(vec3d_t a, vec3d_t b)
{
	return (((a.x * b.x * c.x) + (a.y * b.y * c.y)) \
			/
			(vec_len3d(&a) * vec_len3d(&b)))
}
