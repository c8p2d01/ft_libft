/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unique_insert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:41:47 by cdahlhof          #+#    #+#             */
/*   Updated: 2024/04/13 20:52:29 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_unique_insert(t_list **lst, t_list *new, \
											bool (*iseq)(t_list *a, t_list *b))
{
	t_list	*i;

	i = NULL;
	if (!new)
		return ;
	if (!(*lst))
		(*lst) = new;
	(*lst) = ft_lstfirst((*lst));
	while (lst && (*lst) && !iseq((*lst), new))
		(*lst) = (*lst)->next;
	if (!(*lst)->next)
	{
		new->prev = (*lst);
		(*lst)->next = new;
	}
}
