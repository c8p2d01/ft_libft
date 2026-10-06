#include "../ft_list.h"

/**
 * @brief allocate for a new list block, set its content
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = ft_malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
