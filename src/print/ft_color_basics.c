/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_basics.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:41:12 by cdahlhof          #+#    #+#             */
/*   Updated: 2024/04/04 18:00:39 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

#define RED		"\e[38;2;255;0;0m"
#define MAGENTA	"\e[38;2;255;255;0m"
#define BLUE	"\e[38;2;0;255;0m"
#define GREEN	"\e[38;2;0;0;255m"
#define YELLOW	"\e[38;2;255;0;255m"
#define ORANGE	"\e[38;2;128;0;128m"

t_color	new_color(int r, int g, int b)
{
	t_color	res;

	res.r = r;
	res.g = g;
	res.b = b;
	return (res);
}

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
