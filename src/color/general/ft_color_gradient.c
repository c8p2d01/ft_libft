#include "../ft_color.h"

t_color	create_gradient_color(float fraction, t_color a, t_color b)
{
	t_color result;

	fraction -= (int)fraction;
	result.r = a.r + fraction * ((b.r - a.r) % 256);
	result.g = a.g + fraction * ((b.g - a.g) % 256);
	result.b = a.b + fraction * ((b.b - a.b) % 256);
	return (result);
}

/**
 * @brief return a color on the range if colors provided at the point of \
 * 'fraction' of the total range, colors given ad int r,g,b argiments
 * @param fraction position in the color range
 * @param nColor number of triplet arguments defining the used colors, min 2
 */
t_color	create_multi_gradient(float fraction, int nColor, ...)
{
	int		start_gradient;
	t_color	start;
	t_color	next;
	int		skip;
	va_list	col;

	start_gradient = (int)(fraction * (float)nColor);
	skip = 0;
	fraction -= (int)fraction;
	va_start(col, nColor);
	while (skip < start_gradient * 3)
	{
		(void)va_arg(col, int);
		skip++;
	}
	start = new_color(va_arg(col, int), va_arg(col, int), va_arg(col, int));
	next = new_color(va_arg(col, int), va_arg(col, int), va_arg(col, int));
	fraction = (fraction * (float)nColor) - (start_gradient);
	return (create_gradient_color(fraction, start, next));
}
