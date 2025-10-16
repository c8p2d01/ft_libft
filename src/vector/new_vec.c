/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_vec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 02:32:35 by cdahlhof          #+#    #+#             */
/*   Updated: 2025/10/16 08:25:30 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vec3d	new_vec3d(double x, double y, double z)
{
	t_vec3d res = (t_vec3d){
		.x = x,
		.y = y,
		.z = z
	};
	return (res);
}

t_vec2d	new_vec2d(double x, double y)
{
	t_vec2d res = (t_vec2d){
		.x = x,
		.y = y
	};
	return (res);
}
