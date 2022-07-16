/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:20:33 by clems             #+#    #+#             */
/*   Updated: 2022/07/16 20:39:04 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// append an element at the end of the given list
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*finit;

	if (lst)
	{
		if (*lst)
		{
			finit = ft_lstlast(*lst);
			finit->next = new;
		}
		else
			*lst = new;
	}
}
