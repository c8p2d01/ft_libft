#include "../ft_list.h"

/**
 * @brief delete an element, keeping the list intact
 */
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

/**
 * @brief delete n elements from the end of the list
 */
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
