/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:41:56 by cdahlhof          #+#    #+#             */
/*   Updated: 2024/10/20 06:00:57 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst)
		(*del)(lst->content);
	free(lst);
}

// int main()
// {
// 	t_list	*start = ft_lstnew("start");
// 	ft_lstadd_back(&start, ft_lstnew("next"));
// 	ft_lstadd_back(&start, ft_lstnew("last"));
// 	printf("b %p  n %p  l %p\n", start, start->next, start->next->next);
// 	ft_lstdelone(start->next, NULL);
// 	printf("b %p, n %p\n", start, start->next);
// }
