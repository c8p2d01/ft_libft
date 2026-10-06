#include "../ft_list.h"

/**
 * @brief insert at the top an element, unless the an element has content that matches the given, according to the given function
 */
void	ft_unique_insert(t_list **lst, t_list *new, \
											bool (*iseq)(t_list *a, t_list *b))
{
	if (!new)
		return ;
	if (!(*lst))
		(*lst) = new;
	(*lst) = ft_lstfirst((*lst));
	while (lst && (*lst) && !iseq((*lst), new))
		(*lst) = (*lst)->next;
	if (!(*lst)->next)
	{
		new->prev = (*lst);
		(*lst)->next = new;
	}
}
