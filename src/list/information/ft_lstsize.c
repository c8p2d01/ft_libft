#include "../ft_list.h"

/**
 * @brief find the length of the list
 */
int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	lst = ft_lstfirst(lst);
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
