#include "../ft_list.h"

/**
 * @brief cut an element out of its list neighbours, keeping the list intact.
 * list pointer only used in case head of list was cut
 */
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
