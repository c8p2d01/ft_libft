#include "../ft_list.h"

/**
 * @brief search for an element, where the content matches the given, according to the given function
 * @return the found element
 */
t_list	*ft_lstfind(t_list *lst, void *target, bool eq(void*, void*))
{
	while (lst)
	{
		if (eq(lst->content, target))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

/**
 * @brief search for an element, where the content matches the given, according to the given function
 * @return the index in the list of the found element
 */
int	ft_lstlocate(t_list *lst, void *target, bool eq(void*, void*))
{
	int	i;

	i = 0;
	while (lst)
	{
		if (eq(lst->content, target))
			return (i);
		lst = lst->next;
		i++;
	}
	return (-1);
}
