#include "../ft_color.h"

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	color_to_rgb(t_color a)
{
	return (a.r << 16 | a.g << 8 | a.b);
}

int	color_to_rgbt(t_color a, int alpha)
{
	return (a.r << 24 | a.g << 16 | a.b << 8 | (unsigned char)alpha);
}

int	color_to_trgb(t_color a, int alpha)
{
	return ((unsigned char)alpha << 24 | a.r << 16 | a.g << 8 | a.b);
}
