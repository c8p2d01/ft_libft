/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 02:32:35 by cdahlhof          #+#    #+#             */
/*   Updated: 2024/09/09 02:36:06 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

double	angle2d(t_vec2d a, t_vec2d b)
{
	return (acos(((a.x * b.x) + (a.y * b.y)) / (veclen2d(&a) * veclen2d(&b))));
}

double	angle3d(t_vec3d a, t_vec3d b)
{
	return (acos(((a.x * b.x) + (a.y * b.y) + (a.z * b.z)) / \
				(veclen3d(&a) * veclen3d(&b))));
}
