#include "ft_vector.h"

double	angle2d(vec2d_t a, vec2d_t b)
{
	return (acos(((a.x * b.x) + (a.y * b.y)) / (veclen2d(&a) * veclen2d(&b))));
}

double	angle3d(vec3d_t a, vec3d_t b)
{
	return (acos(((a.x * b.x) + (a.y * b.y) + (a.z * b.z)) / \
				(veclen3d(&a) * veclen3d(&b))));
}
