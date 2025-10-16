/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subtraction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 02:32:35 by cdahlhof          #+#    #+#             */
/*   Updated: 2025/10/16 08:24:18 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vec3d	connect3d(t_vec3d a, t_vec3d b)
{
	t_vec3d res;

	res = (t_vec3d){
		.x = a.x - b.x,
		.y = a.y - b.y,
		.z = a.z - b.z
	};
	return (res);
}

t_vec2d	connect2d(t_vec2d a, t_vec2d b)
{
	t_vec2d res;

	res = (t_vec2d){
		.x = a.x - b.x,
		.y = a.y - b.y
	};
	return (res);
}