#include "../ft_list.h"

/**
 * @brief perform a function on each element of the list
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (f)
	{
		while (lst)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
}
