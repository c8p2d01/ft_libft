/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:46:18 by cdahlhof          #+#    #+#             */
/*   Updated: 2025/10/10 14:57:42 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

t_list **storage_pools()
{
	static t_list	*pools;

	return (&pools);
}

t_mem	*get_pool(size_t size)
{
	t_list	*i;
	t_mem	*mem;

	i = *storage_pools();
	while (i)
	{
		mem = (t_mem *)i->content;
		if (mem->size == size)
			return (mem);
		i = i->next;
	}
	return (NULL);
}

void	*ft_recycalloc(size_t size)
{
	t_mem	*mem;
	size_t	len;
	t_list	*block;
	t_list	**used_memory;

	mem = get_pool(size);
	if (mem)
	{
		len = ft_lstsize(mem->mem);
		if (len > 0)
		{
			block = ft_lstlast(mem->mem);
			block = ft_lst_extract(&mem->mem, block);
			if (block)
			{
				used_memory = memory();
				ft_lstadd_back(used_memory, block);
				return (block->content);
			}
		}
	}
	return (NULL);
}

t_mem	*new_pool(size_t size)
{
	t_mem	*p;
	t_list	*storage;
	t_list	*new;

	p = malloc(sizeof(t_mem));
	p->n_hold = 4;
	p->size = size;
	p->mem = NULL;
	new = ft_lstnew(p);
	storage = *storage_pools();
	if (!storage)
		*storage_pools() = new;
	else
		ft_lstadd_back(&storage, new);
	return (p);
}

void	ft_store_mem(void *del, size_t size)
{
	t_list	*all_mem;
	t_list	*block;
	t_mem	*mem;

	mem = get_pool(size);
	if (!mem)
		mem = new_pool(size);
	all_mem = *memory();
	if (!del)
		return ;
	while (all_mem && all_mem->content && all_mem->content != del)
		all_mem = all_mem->next;
	if (all_mem)
	{
		block = ft_lst_extract(memory(), all_mem);
		if ((unsigned long)ft_lstsize(mem->mem) < mem->n_hold)
		{
			ft_bzero(block->content, size);
			ft_lstadd_back(&mem->mem, block);
		}
		else
		{
			free(del);
			free(block);
		}
	}
	else
		free(del);
}

void	ft_set_pool_size(size_t size, size_t n_hold)
{
	t_mem	*pool;
	t_list	*blocks;
	size_t	i;

	pool = get_pool(size);
	if (pool)
	{
		pool->n_hold = n_hold;
		blocks = pool->mem;
		i = ft_lstsize(blocks);
		if (i > (unsigned long)n_hold)
			ft_list_del_last_n(blocks, free, i - n_hold);
	}
}

//void	*ft_malloc(size_t size)
//{
//	t_list	*mem;
//	t_list	*new;
//	void	*content;

//	content = malloc(size);
//	if (!content)
//		exit(1);
//	ft_bzero(content, size);
//	new = ft_memnew(content);
//	mem = *memory();
//	if (mem != NULL)
//		ft_lstadd_back(&mem, new);
//	else
//		*memory() = new;
//	return (content);
//}

//void	ft_free(void *del_block)
//{
//	t_list	**mem_list;
//	t_list	*p_list;

//	mem_list = memory();
//	p_list = *mem_list;
//	if (!del_block)
//		return ;
//	if (p_list && p_list->content && p_list->content == del_block)
//	{
//		*mem_list = p_list->next;
//	}
//	else
//	{
//		while (p_list)
//		{
//			if (p_list->content && p_list->content == del_block)
//				break ;
//			p_list = (p_list)->next;
//		}
//	}
//	ft_lstdelone(p_list, NULL);
//	if (del_block)
//		free(del_block);
//	del_block = NULL;
//}

//void	ft_clean_allocs(void)
//{
//	t_list	*l;
//	t_list	*t;

//	l = *memory();
//	while (l)
//	{
//		t = l->next;
//		if (l->content)
//		{
//			ft_free(l->content);
//		}
//		l = t;
//	}
//	l = *memory();
//	ft_lstclear(&l, free);
//	*memory() = NULL;
//}

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
