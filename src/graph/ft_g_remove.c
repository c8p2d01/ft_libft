/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_g_remove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 21:24:24 by cdahlhof          #+#    #+#             */
/*   Updated: 2024/03/14 22:21:08 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

/**
 * @brief Deactive a link between 2
 */
void	ft_g_unlink(t_gnode *node, t_gnode *next)
{
	t_list	*rmvNode;
	t_link	*link;

	if (!node || !next)
		return ;
	rmvNode = node->links;
	while (rmvNode)
	{
		if (ft_is_link(rmvNode->content, node, next))
		{
			link = rmvNode->content;
			if (link)
			{
				ft_lstdelone(rmvNode, NULL);
				ft_g_unlink(next, node);
			}
			if (link)
				free(link);
			break ;
		}
		rmvNode = rmvNode->next;
	}
}

/**
 * @brief Delete a node and remove all links to it
 */
void	ft_g_del_node(t_gnode *node, void (*del)(void*))
{
	t_list	*currentLink;
	t_list	*nextLink;
	t_link	*actualLink;

	if (!node)
		return ;
	currentLink = node->links;
	while (currentLink)
	{
		nextLink = currentLink->next;
		actualLink = currentLink->content;
		ft_g_unlink(actualLink->from, actualLink->to);
		currentLink = nextLink;
	}
	if (node->name)
		free(node->name);
	if (node->links)
		free(node->links);
	if (del && node->content)
		del(node->content);
	free(node);
}
