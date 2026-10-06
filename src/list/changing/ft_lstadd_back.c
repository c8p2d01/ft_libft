#include "../ft_list.h"

/**
 * @brief append an element to an existing list or set the element to be the head of a new one
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*i;

	i = NULL;
	if (!new)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		i = ft_lstlast((*lst));
		i->next = new;
		new->prev = i;
	}
}
