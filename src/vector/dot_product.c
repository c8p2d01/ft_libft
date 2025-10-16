/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_product.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 02:32:35 by cdahlhof          #+#    #+#             */
/*   Updated: 2025/10/16 08:25:16 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

double	dot_2d(t_vec2d a, t_vec2d b)
{
	return ((a.x * b.x) + (a.y * b.y));
}

double	dot_3d(t_vec3d a, t_vec3d b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}
