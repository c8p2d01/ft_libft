/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:08:04 by cdahlhof          #+#    #+#             */
/*   Updated: 2024/12/19 21:24:23 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

/**
 * @brief Allocate a new node
 */
t_graph	*ft_new_graph(void *content)
{
	t_graph	*res;

	res = ft_calloc(sizeof(t_graph), 1);
	if (res == NULL)
		return (NULL);
	*res = (t_graph){
		.links = NULL,
		.content = content
	};
	return (res);
}

/**
 * @brief Deactive a link between 2
 */
void	ft_unlink(t_graph *node, t_graph *next)
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
 * @brief Delete a node, keeping the net intact
 * @param node it
 * @param del the deletion function sun on the content/info
 */
void	ft_cut_graph(t_graph *node, void (*del)(void*))
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
	if (node->links)
		free(node->links);
	if (del && node->content)
		del(node->content);
	free(node);
}

/**
 * @brief Delete a node, breaking the links and the net
 * @param node it
 * @param del the deletion function sun on the content/info
 */
void	ft_rip_graph(t_graph *node, void (*del)(void*))
{
	if (!node)
		return ;
	if (node->links)
		free(node->links);
	if (del && node->content)
		del(node->content);
	free(node);
}
