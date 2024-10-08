/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 02:52:15 by cdahlhof          #+#    #+#             */
/*   Updated: 2024/09/09 02:53:26 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vec2d	rotate2d(t_vec2d *vector, double degree)
{
	t_vec2d	result;
	double	rad;

	rad = degree * PI / 180;
	result.x = vector->x * cos(rad) - vector->y * sin(rad);
	result.y = vector->x * sin(rad) + vector->y * cos(rad);
	return (result);
}
