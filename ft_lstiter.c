/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:56:01 by clems             #+#    #+#             */
/*   Updated: 2022/07/16 20:38:41 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// apply the function f to every element of the current
// and every following element
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != 0 && f != 0)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
