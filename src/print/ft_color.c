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

// color codes in rainbow sequence (len=30) for \e[38;5;%im{...}
int	colorflow(int i)
{
	int	m;

	m = i % 30;
	if (m < 6)
		return (21 + (m * 36));
	if (m < 11)
		return (200 - (m - 6));
	if (m < 16)
		return (202 + ((m - 11) * 6));
	if (m < 21)
		return (190 - ((m - 16) * 36));
	if (m < 26)
		return (47 + (m - 21));
	if (m < 31)
		return (45 - ((m - 26) * 6));
	return (0);
}

long	create_gradient_color(float fraction, t_color a, t_color b)
{
	int	red;
	int	green;
	int	blue;

	fraction -= (int)fraction;
	red = a.r + fraction * (b.r - a.r);
	green = a.g + fraction * (b.g - a.g);
	blue = a.b + fraction * (b.b - a.b);
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
	--nColor;
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

/**
 * @param color => ("rrbbgg")
*/
int	terminal_rgb(char *color)
{
	char			*color_snippet;
	unsigned char	rgb[3];
	int				i;

	if (color[0] == '#')
		color++;
	i = 0;
	while (i < 3)
	{
		rgb[i] = 0;
		color_snippet = ft_substr(color, i * 2, 2);
		if (ft_strlen(color_snippet))
		{
			printf("\t\t%s\n", color_snippet);
			ft_tolower(color_snippet[0]);
			ft_tolower(color_snippet[1]);
			rgb[i] = ft_atoi_base(color_snippet, "0123456789abcdef");
		}
		free (color_snippet);
		i++;
	}
	printf("\e[48;%i;%i;%im", rgb[0], rgb[1], rgb[2]);
	return (0);
}
