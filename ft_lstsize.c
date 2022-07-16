/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 19:09:00 by clems             #+#    #+#             */
/*   Updated: 2022/07/16 20:38:27 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// count and return the length of a list
int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*current;

	i = 1;
	current = lst;
	if (lst)
	{
		while ((current->next) != NULL)
		{
			current = current->next;
			i++;
		}
	}
	else
		return (0);
	return (i);
}
