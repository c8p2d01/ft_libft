/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:41:56 by cdahlhof          #+#    #+#             */
/*   Updated: 2025/10/10 13:25:19 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

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
