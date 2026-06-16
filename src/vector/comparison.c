/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparison.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 02:32:35 by cdahlhof          #+#    #+#             */
/*   Updated: 2024/09/09 02:36:06 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

bool	equal2d(t_vec2d *a, t_vec2d *b, double precision)
{
	double	px;
	double	py;

	px = a->x - b->x;
	py = a->y - b->y;
	if (-precision < px && px < precision && 
		-precision < py && py < precision)
		return (true);
	return(false);
}

bool	equal3d(t_vec3d *a, t_vec3d *b, double precision)
{
	double	px;
	double	py;
	double	pz;

	px = a->x - b->x;
	py = a->y - b->y;
	pz = a->z - b->z;
	if (-precision < px && px < precision && 
		-precision < py && py < precision && 
		-precision < pz && pz < precision)
		return (true);
	return(false);
}
