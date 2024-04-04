/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_g_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 21:24:35 by cdahlhof          #+#    #+#             */
/*   Updated: 2024/04/04 18:06:12 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

/**
 * @brief Insert one node to another
 */
void	ft_g_insert(t_gnode *node, t_gnode *next)
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
	new_link = ft_lstnew(ft_new_link(node, next));
	ft_lstadd_back(&(node->links), new_link);
	ft_lstadd_back(&(next->links), new_link);
	return ;
}
