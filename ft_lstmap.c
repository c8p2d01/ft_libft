/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clems <clems@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:57:03 by clems             #+#    #+#             */
/*   Updated: 2021/05/28 10:46:22 by clems            ###   ########.fr       */
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
static void	ft_lstadd_back_include_sux(t_list **lst, t_list *new)
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
static t_list	*ft_lstnew_lol(void *content)
{
	t_list	*first;

	first = (t_list *)malloc(sizeof(t_list));
	first->content = content;
	first->next = NULL;
	return (first);
}

// deletes the current and the following elements
static void	ft_lstclear_weeeeee(t_list **lst, void (*del)(void *))
{
	t_list	*current;

	if (lst && del && *lst)
	{
		while (*lst)
		{
			current = (*lst)->next;
			if (lst && del)
			{
				(*del)((*lst)->content);
				free(*lst);
			}
			(*lst) = current;
		}
	}
	return ;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void			*f_;
	t_list			*res;
	t_list			*new;
	t_list			*org;

	res = NULL;
	new = NULL;
	org = lst;
	while (lst)
	{
		f_ = f(lst->content);
		if (f_)
		{
			new = ft_lstnew_lol(f_);
			if (!new)
			{
				ft_lstclear_weeeeee(&lst, del);
				return (NULL);
			}
			ft_lstadd_back_include_sux(&res, new);
		}
		lst = lst->next;
	}
	lst = org;
	return (res);
}
