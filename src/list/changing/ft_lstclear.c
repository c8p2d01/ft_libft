#include "../ft_list.h"

/**
 * @brief completely detete a list, using the given function to clear the content
 */
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (*lst)
	{
		if ((*lst)->next)
			ft_lstclear(&(*lst)->next, del);
		(*lst)->next = NULL;
		ft_lstdelone(*lst, del);
		*lst = NULL;
	}
}
