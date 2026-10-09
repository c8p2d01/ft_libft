#include "../ft_graph.h"

/**
 * @brief check if the two given nodes already have a link
 */
t_link	*ft_are_linked(t_graph *a, t_graph *b)
{
	t_list	*i;
	t_link	*a_link;
	t_link	*b_link;

	if (!a || !b)
		return (NULL);
	i = a->links;
	a_link = NULL;
	while(i)
	{
		a_link = i->content;
		if (!a_link)
			break ;
		if (((a_link->from == a && a_link->to == b) || \
			(a_link->from == b && a_link->to == a)))
			break ;
		i = i->next;
	}
	i = b->links;
	while(i)
	{
		b_link = i->content;
		if (b_link == a_link && a_link)
			return (a_link);
		i = i->next;
	}
	return (NULL);
}

t_link	*ft_are_actively_linked(t_graph *a, t_graph *b)
{
	t_link	*link;

	link = ft_are_linked(a, b);
	if (link && link->active)
	{
		return (link);
	}
	return (NULL);
}
