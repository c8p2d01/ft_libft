/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clems <clems@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:54:54 by clems             #+#    #+#             */
/*   Updated: 2021/05/29 17:00:09 by clems            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// applies the deleting function to the given element
static void	ft_lstdelone_include_sux(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		(*del)(lst->content);
		free(lst);
	}
}

// deletes the current and the following elements
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;

	if (lst && del && *lst)
	{
		while (*lst)
		{
			current = (*lst)->next;
			ft_lstdelone_include_sux(*lst, del);
			(*lst) = current;
		}
	}
	return ;
}
