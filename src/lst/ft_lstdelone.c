/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:41:56 by cdahlhof          #+#    #+#             */
/*   Updated: 2025/08/09 23:12:48 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

t_list	*ft_lst_extract(t_list **lst, t_list *node)
{
	t_list	temp;

	if (!node)
		return (NULL);

	temp.next = node->next;
	temp.prev = node->prev;
	if (node->prev)
		node->prev->next = temp.next;
	if (node->next)
		node->next->prev = temp.prev;
	node->next = NULL;
	node->prev = NULL;
	if (lst && *lst == node)
		*lst = node->next;
	return (node);
}

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	t_list	*n;
	t_list	*p;

	n = NULL;
	p = NULL;
	if (lst)
	{
		n = lst->next;
		p = lst->prev;
		if (n)
			n->prev = p;
		if (p)
			p->next = n;
	}
	if (lst && del && lst->content)
	{
		del(lst->content);
		lst->content = NULL;
	}
	if (lst)
		ft_free(lst);
	lst = NULL;
}

void	ft_list_del_last_n(t_list *lst, void (*del)(void*), size_t n_nodes)
{
	size_t	len;
	t_list	*next;

	len = ft_lstsize(lst);
	while (lst && len - n_nodes > 0)
	{
		lst = lst->next;
		len--;
	}
	while (lst && n_nodes > 0)
	{
		next = lst->next;
		ft_lstdelone(lst, del);
		lst = next;
		n_nodes--;
	}
}

// int main()
// {
// 	t_list	*start = ft_lstnew("start");
// 	ft_lstadd_back(&start, ft_lstnew("next"));
// 	ft_lstadd_back(&start, ft_lstnew("last"));
// 	printf("b %p  n %p  l %p\n", start, start->next, start->next->next);
// 	ft_lstdelone(start->next, NULL);
// 	printf("b %p, n %p\n", start, start->next);
// }
