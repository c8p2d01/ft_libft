/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clems <clems@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:20:33 by clems             #+#    #+#             */
/*   Updated: 2021/05/27 19:42:23 by clems            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns the last element of the list
static t_list	*ft_lstlast_because_include_sux(t_list *lst)
{
	t_list	*current;

	current = lst;
	while (current->next != NULL)
		current = current->next;
	return (current);
}

// append an element at the end of the given list
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*finit;

	if (lst)
	{
		if (*lst)
		{
			finit = ft_lstlast_because_include_sux(*lst);
			finit->next = new;
		}
		else
			*lst = new;
	}
}
