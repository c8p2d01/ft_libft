#include "../ft_list.h"

/**
 * @brief add an elemtent as the Head of a list, keeping the Tail intacts if it existed
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*i;

	i = NULL;
	if (!new)
		return ;
	if (!(*lst))
	{
		*lst = new;
	}
	else
	{
		i = ft_lstfirst((*lst));
		i->prev = new;
		new->next = i;
	}
}

// int main(int argc, char **argv)
// {
// 	t_list	*lal = NULL;
// 	t_list	*tmp = NULL;
// 	t_list	*new = NULL;

// 	for(int i = 0; i < argc; i++)
// 	{
// 		new = ft_lstnew(argv[i]);
// 		tmp = ft_lstlast(tmp); 
// 		ft_lstadd_front(&tmp, new);
// 		printf("%s %p %p\n", new->content, new, new->next);
// 	}
// 	lal = ft_lstfirst(lal);
// 	while (lal)
// 		{printf("%s\n", lal->content);lal = lal->next;}
// }
