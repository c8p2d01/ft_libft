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

#include "../../inc/libft.h"

t_list	**memory(void)
{
	static t_list	*mem;

	return (&mem);
}

t_list	*ft_memnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	*ft_malloc(size_t size)
{
	t_list	*mem;
	t_list	*new;
	void	*content;

	content = malloc(size);
	if (!content)
		exit(1);
	ft_bzero(content, size);
	new = ft_memnew(content);
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
	else
	{
		while (p_list)
		{
			if (p_list->content && p_list->content == del_block)
				break ;
			p_list = (p_list)->next;
		}
	}
	ft_lstdelone(p_list, NULL);
	if (del_block)
		free(del_block);
	del_block = NULL;
}

void	ft_clean_allocs(void)
{
	t_list	*l;
	t_list	*t;

	l = *memory();
	while (l)
	{
		t = l->next;
		if (l->content)
		{
			ft_free(l->content);
		}
		l = t;
	}
	l = *memory();
	ft_lstclear(&l, free);
	*memory() = NULL;
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
