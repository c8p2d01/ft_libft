/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:41:12 by cdahlhof          #+#    #+#             */
/*   Updated: 2024/09/09 13:07:19 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

long	create_gradient_color(float fraction, t_color a, t_color b)
{
	int	red;
	int	green;
	int	blue;

	fraction -= (int)fraction;
	red = a.r + fraction * ((b.r - a.r) % 256);
	green = a.g + fraction * ((b.g - a.g) % 256);
	blue = a.b + fraction * ((b.b - a.b) % 256);
	return (0 << 24 | (unsigned char)red << 16 | (unsigned char)green << 8 \
													| (unsigned char)blue);
}

/**
 * @brief return a color on the range if colors provided at the point of \
 * 'fraction' of the total range, colors given ad int r,g,b argiments
 * @param fraction position in the color range
 * @param nColor number of triplet arguments defining the used colors, min 2
 */
long	create_multi_gradient(float fraction, int nColor, ...)
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

int	terminal_rgb(char r, char b, char g, bool background)
{
	return (printf("\e[I%i;%i;%i;%im", background ? 48 : 38, r, g, b));
}

/**
 * print the color code that represents the color at the position num, over the range of low -> high which gors through the outer rgb rainbow
 * if c is not space, then the characters will be colored, otherwise the background will be colored
 */
void	color_range(int num, int low, int high, char c)
{
	int div = high - low;
	float	frac = (float)num / (float)div;
	if (frac < 0)
		frac += 1;
	long color = create_multi_gradient(frac, 6, 255,0,0, 255,255,0, 0,255,0, 0,255,255, 0,0,255, 255,0,255);
	printf("\e[%i;2;%li;%li;%lim%c", (c == ' ' ? 48 : 38), (color>>16)%256, (color>>8)%256, (color)%256, c);
}
