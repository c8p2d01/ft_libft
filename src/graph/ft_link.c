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
t_link	*ft_new_link(t_graph *in, t_graph *out, void *info)
{
	t_link	*res;

	res = malloc(sizeof(t_link));
	if (!res)
		return (NULL);
	*res = (t_link){
		.from = in,
		.to = out,
		.info = info
	};
	return (res);
}

/**
 * @brief link one node to another
 */
void	ft_link_nodes(t_graph *node, t_graph *next, \
										void *(*info)(t_graph *, t_graph *))
{
	t_list	*new_link;
	t_list	*check_link;

	check_link = node->links;
	while (check_link)
	{
		if (ft_is_link(check_link->content, node, next))
			return ;
		check_link = check_link->next;
	}
	new_link = ft_lstnew(ft_new_link(node, next, info(node, next)));
	ft_lstadd_back(&(node->links), new_link);
	ft_lstadd_back(&(next->links), new_link);
	return ;
}

/**
 * @brief Check if graph a is linked to graph b
 */
bool	ft_is_link(t_link *link, t_graph *a, t_graph *b)
{
	if (link->from == a && link->to == b)
		return (true);
	if (link->from == b && link->to == a)
		return (true);
	return (false);
}

/**
 * @brief returns the node being linked to
 */
t_graph	*ft_otherside(t_link *link, t_graph *myside)
{
	if (!link || !myside)
		return (NULL);
	if (link->from == myside)
		return (link->to);
	if (link->to == myside)
		return (link->from);
	return (NULL);
}

/**
 * @brief check if node a has an active link to node b
 * @param a; t_graph *
 * @param b; t_graph *
 */
bool	ft_has_link(t_graph *a, t_graph *b)
{
	t_list	*current_link;

	if (!a || !b)
		return (false);
	current_link = a->links;
	while (current_link)
	{
		if (ft_is_link(current_link->content, a, b))
			return (true);
		current_link = current_link->next;
	}
	return (false);
}
