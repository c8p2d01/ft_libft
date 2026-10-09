#include "../ft_color.h"

int	terminal_rgb(char r, char b, char g, bool background)
{
	return (printf("\e[I%i;%i;%i;%im", background ? 48 : 38, r, g, b));
}

int	terminal_color(t_color a, bool background)
{
	if (background)
		return (printf("\e[I%i;%i;%i;%im", 48, a.r, a.g, a.b));
	return (printf("\e[I%i;%i;%i;%im", 38, a.r, a.g, a.b));
}

/**
 * prints the color corresponding to the position in the rainbow+ range
 */
void	color_range(int num, int low, int high, char c)
{
	int div = high - low;
	float	frac = (float)num / (float)div;
	if (frac < 0)
		frac += 1;
	t_color color = create_multi_gradient(frac, 6, 255,0,0, 255,255,0, 0,255,0, 0,255,255, 0,0,255, 255,0,255);
	printf("\e[38;2;%i;%i;%im%c",
		(color.r) % 256,
		(color.g) % 256,
		(color.b) % 256,
		c);
}
