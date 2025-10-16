/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:41:07 by cdahlhof          #+#    #+#             */
/*   Updated: 2025/10/10 19:07:05 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include "../../inc/libft.h"

typedef struct s_list	t_list;
struct		s_list
{
	void	*content;
	t_list	*next;
	t_list	*prev;
};

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstfirst(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

bool		ft_lst_iseq(t_list *a, t_list *b);
void		ft_unique_insert(t_list **lst, t_list *new, \
										bool (*iseq)(t_list *a, t_list *b));
t_list		*ft_lstfind(t_list *lst, void *target, bool eq(void*, void*));
int			ft_lstlocate(t_list *lst, void *target, bool eq(void*, void*));

#endif