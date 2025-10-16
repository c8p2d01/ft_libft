/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplication.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 02:32:35 by cdahlhof          #+#    #+#             */
/*   Updated: 2025/10/16 08:24:34 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vec3d	product3d(t_vec3d a, double m)
{
	t_vec3d res;

	res = (t_vec3d){
		.x = a.x * m,
		.y = a.y * m,
		.z = a.z * m
	};
	return (res);
}

t_vec2d	product2d(t_vec2d a, double m)
{
	t_vec2d res;

	res = (t_vec2d){
		.x = a.x * m,
		.y = a.y * m
	};
	return (res);
}
