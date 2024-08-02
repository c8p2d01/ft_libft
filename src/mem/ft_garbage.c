/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:41:17 by cdahlhof          #+#    #+#             */
/*   Updated: 2023/01/02 15:14:54 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/**
 * garbaage collection by storing all allocation poiners in a list
 * the head of the list is static stored and retrieved in this function
 * @return pointer to the address of the HEAD of the allocation list
 */
t_list	**head()
{
	static t_list	*head;

	return (&head);
}

/**
 * allocate using malloc, but store the address to ease the cleanup later
 */
void	*ft_malloc(size_t	size)
{
	t_list	**mem_list;
	t_list	*new_list;
	void	*new_block;

	mem_list = head();
	new_block = malloc(size);
	new_list = ft_lstnew(new_block);
	if (new_block)
		ft_lstadd_back(mem_list, new_list);
	return (new_block);
}

/**
 * free any pointer and if it is found in the memory-collection-list, remove it
 */
void	ft_free(void *del_block)
{
	t_list	**mem_list;
	t_list	*p_list;

	mem_list = head();
		printf("\t%p\n", *mem_list);
	p_list = *mem_list;
	if (!del_block)
		return ;
	if (p_list && p_list->content && p_list->content == del_block)
	{
		*mem_list = p_list->next;
	}
	while (p_list)
	{
		printf("\t%p\n", p_list->content);
		if (p_list->content && p_list->content == del_block)
		{
			break;
		}
		p_list = (p_list)->next;
	}
	ft_lstdelone(p_list, NULL);
		printf("\t%p\n", *mem_list);
	free(del_block);
}

void	ft_clean_allocs()
{
	ft_lstclear(head(), free);
}

// void	print_garb()
// {
// 	t_list	**garb;
// 	t_list	*p_list;

// 	garb = head();
// 	p_list = *garb;
// 	while (p_list)
// 	{
// 		if ((p_list)->content)
// 			printf("garb %p\n", (p_list)->content);
// 		p_list = (p_list)->next;
// 	}
// 	printf("\n");
// }

// int main()
// {
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

// 	ft_lstclear(head(), free);
// 	printf("freed\n");
// 	print_garb();
// }
