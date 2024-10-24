/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:42:10 by cdahlhof          #+#    #+#             */
/*   Updated: 2024/10/22 19:17:27 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*node;
	void	*result;

	new = NULL;
	while (lst)
	{
		if (lst->content)
		{
			result = f(lst->content);
			node = ft_lstnew(result);
			if (!node)
			{
				ft_lstclear(&new, del);
				if (new)
					free(new);
				del(result);
				return (NULL);
			}
			ft_lstadd_back(&new, node);
		}
		lst = lst->next;
	}
	return (new);
}
