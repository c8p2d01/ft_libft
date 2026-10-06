#include "../ft_list.h"

/**
 * @brief find the first element of the list
 */
t_list	*ft_lstfirst(t_list *lst)
{
	while (lst && lst->prev != NULL)
		lst = lst->prev;
	return (lst);
}
