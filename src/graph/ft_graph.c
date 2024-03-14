/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:08:04 by cdahlhof          #+#    #+#             */
/*   Updated: 2024/03/14 22:24:44 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

/**
 * @brief Allocate a new node
 */
t_gnode	*ft_g_new_node(char *name, void *content)
{
	t_gnode	*res;

	res = ft_calloc(sizeof(t_gnode), 1);
	if (res == NULL)
		return (NULL);
	*res = (t_gnode){
		.links = NULL,
		.name = name,
		.content = content
	};
	return (res);
}
