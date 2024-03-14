/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:08:04 by cdahlhof          #+#    #+#             */
/*   Updated: 2023/01/14 15:25:46 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

/**
 * @brief Allocate new link
 */
t_link	*ft_new_link(t_gnode *in, t_gnode *out)
{
	t_link	*res;

	res = malloc(sizeof(t_link));
	if (!res)
		return (NULL);
	*res = (t_link){
		.from = in,
		.to = out,
		.capacity = 0,
		.active = true
	};
	return (res);
}

/**
 * @brief Check if gnode a is linked to gnode b
 */
bool	ft_is_link(t_link *link, t_gnode *a, t_gnode *b)
{
	if (link->from == a && link->to == b)
		return (true);
	if (link->from == b && link->to == a)
		return (true);
	return (false);
}

/**
 * @brief return the capacity vlaue of the link (negative if towards node)
 * @param link, t_link * ::	the link that holds the capacity
 * @param mode, t_gnode *	::	the gnode the capacity starts from
 * @return int			::	the capacity towards the connected node
 */
int	ft_g_capacity(t_link *link, t_gnode *node)
{
	if (!link || !node || !link->from || !link->to)
		return (FLOW_ERROR);
	if (link->from == node)
		return (link->capacity);
	if (link->to == node)
		return (-(link->capacity));
	return (FLOW_ERROR);
}

/**
 * @brief check if node a has an active link to node b
 * @param a; t_gnode *
 * @param b; t_gnode *
 */
bool	ft_has_link(t_gnode *a, t_gnode *b)
{
	t_list	*currentLink;

	if (!a || !b)
		return (false);
	currentLink = a->links;
	while (currentLink)
	{
		if (((t_link *)(currentLink->content))->active &&
								ft_is_link(currentLink->content, a, b))
			return (true);
		currentLink = currentLink->next;
	}
	return (false);
}

/**
 * @brief returns the node being linked to
 */
t_gnode	*ft_otherside(t_link *link, t_gnode *myside)
{
	if (!link || !myside)
		return (NULL);
	if (link->from == myside)
		return (link->to);
	if (link->to == myside)
		return (link->from);
	return (NULL);
}
