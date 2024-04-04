/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_g_remove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 21:24:24 by cdahlhof          #+#    #+#             */
/*   Updated: 2024/04/04 18:06:33 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

/**
 * @brief Deactive a link between 2
 */
void	ft_g_unlink(t_gnode *node, t_gnode *next)
{
	t_list	*rmv_node;
	t_link	*link;

	if (!node || !next)
		return ;
	rmv_node = node->links;
	while (rmv_node)
	{
		if (ft_is_link(rmv_node->content, node, next))
		{
			link = rmv_node->content;
			if (link)
			{
				ft_lstdelone(rmv_node, NULL);
				ft_g_unlink(next, node);
			}
			if (link)
				free(link);
			break ;
		}
		rmv_node = rmv_node->next;
	}
}

/**
 * @brief Delete a node and remove all links to it
 */
void	ft_g_del_node(t_gnode *node, void (*del)(void*))
{
	t_list	*current_link;
	t_list	*next_link;
	t_link	*actual_link;

	if (!node)
		return ;
	current_link = node->links;
	while (current_link)
	{
		next_link = current_link->next;
		actual_link = current_link->content;
		ft_g_unlink(actual_link->from, actual_link->to);
		current_link = next_link;
	}
	if (node->name)
		free(node->name);
	if (node->links)
		free(node->links);
	if (del && node->content)
		del(node->content);
	free(node);
}
