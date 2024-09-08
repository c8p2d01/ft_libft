
#include "../../inc/libft.h"

t_list	**memory(void)
{
	static t_list	*mem;

	return (&mem);
}

void	*ft_malloc(size_t size)
{
	t_list	*mem;
	t_list	*new;
	void	*content;

	content = malloc(size);
	if (!content)
		exit(1);
	new = ft_lstnew(content);
	mem = *memory();
	if (mem != NULL)
		ft_lstadd_back(&mem, new);
	else
		*memory() = new;
	return (content);
}

void	ft_free(void *del_block)
{
	t_list	**mem_list;
	t_list	*p_list;

	mem_list = memory();
	p_list = *mem_list;
	if (!del_block)
		return ;
	if (p_list && p_list->content && p_list->content == del_block)
	{
		*mem_list = p_list->next;
	}
	while (p_list)
	{
		if (p_list->content && p_list->content == del_block)
		{
			break;
		}
		p_list = (p_list)->next;
	}
	ft_lstdelone(p_list, NULL);
	free(del_block);
	del_block = NULL;
}

void	ft_clean_allocs()
{
	ft_lstclear(memory(), free);
}

// void	print_garb()
// {
// 	t_list	**garb;
// 	t_list	*p_list;

// 	garb = memory();
// 	p_list = *garb;
// 	while (p_list)
// 	{
// 		if ((p_list)->content)
// 			printf("list %p\tcontent %p\n", p_list, (p_list)->content);
// 		p_list = (p_list)->next;
// 	}
// 	printf("\n");
// }

// void	leakCheck(void)
// {
// 	system("leaks a.out");
// }

// int main()
// {
// 	atexit(leakCheck);
// 	void *norman = malloc(13);
// 	ft_free(norman);

// 	printf("start\n");
// 	print_garb();

// 	void *lal = ft_malloc(1);
// 	printf("an elem %p\n", lal);
// 	print_garb();

// 	void *lel = ft_malloc(1);
// 	printf("another elem %p\n", lel);
// 	print_garb();

// 	ft_free(lal);
// 	printf("freed\n");
// 	print_garb();
// 	ft_free(lel);
// 	printf("freed\n");
// 	print_garb();

// 	ft_lstclear(memory(), free);
// 	printf("freed\n");
// 	print_garb();
// }


