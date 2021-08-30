/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clems <clems@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 17:42:52 by clems             #+#    #+#             */
/*   Updated: 2021/05/28 11:09:42 by clems            ###   ########.fr       */
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
static void	ft_lstadd_back_kcab_ddatsl_tf(t_list **lst, t_list *new)
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

// create a new list
static t_list	*ft_lstnew_whoops(void *content)
{
	t_list	*first;

	first = (t_list *)malloc(sizeof(t_list));
	first->content = content;
	first->next = NULL;
	return (first);
}

// create a new list, cloning the content of the given one
void	ft_lstdup_bonus(t_list *src, t_list *dest)
{
	if (src)
	{
		dest = ft_lstnew_whoops(src->content);
		src = src->next;
	}
	while (src)
	{
		ft_lstadd_back_kcab_ddatsl_tf(&dest, ft_lstnew_whoops(src->content));
		src = src->next;
	}
}
