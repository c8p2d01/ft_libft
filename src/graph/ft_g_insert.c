/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_g_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 21:24:35 by cdahlhof          #+#    #+#             */
/*   Updated: 2024/03/14 22:55:38 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

/**
 * @brief Insert one node to another
 */
void	ft_g_insert(t_gnode *node, t_gnode *next)
{
	t_list	*newLink;
	t_list	*checkLink;

	checkLink = node->links;
	while (checkLink)
	{
		if (ft_is_link(checkLink->content, node, next))
			return ;
		checkLink = checkLink->next;
	}
	newLink = ft_lstnew(ft_new_link(node, next));
	ft_lstadd_back(&(node->links), newLink);
	ft_lstadd_back(&(next->links), newLink);
	return ;
}
