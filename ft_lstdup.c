/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 17:42:52 by clems             #+#    #+#             */
/*   Updated: 2022/07/16 20:38:44 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// create a new list, cloning the content of the given one
void	ft_lstdup(t_list *src, t_list *dest)
{
	if (src)
	{
		dest = ft_lstnew(src->content);
		src = src->next;
	}
	while (src)
	{
		ft_lstadd_back(&dest, ft_lstnew(src->content));
		src = src->next;
	}
}
