/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:36:13 by clems             #+#    #+#             */
/*   Updated: 2022/07/16 20:38:29 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// gets a pointer to an element and returns the pointer to the previous element
t_list	*ft_lstprev(t_list **lst, t_list *follow)
{
	t_list	*current;

	current = NULL;
	if (lst)
	{
		current = *lst;
		while (current->next != 0 && current->next != follow)
			current = current->next;
	}
	return (current);
}
