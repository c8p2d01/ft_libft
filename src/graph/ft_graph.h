/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:41:07 by cdahlhof          #+#    #+#             */
/*   Updated: 2024/03/14 22:55:22 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GRAPH_H
# define FT_GRAPH_H

# define FLOW_ERROR 255

# include "../../inc/libft.h"

typedef struct s_gnode
{
	char			*name;
	void			*content;
	struct s_list	*links;
}	t_gnode;

typedef struct s_link
{
	struct s_gnode	*from;
	struct s_gnode	*to;
	int				capacity;
	bool			active;
}	t_link;

t_gnode	*ft_g_new_node(char *name, void *content);
t_link	*ft_new_link(t_gnode *in, t_gnode *out);
void	ft_g_del_node(t_gnode *node, void (*del)(void*));

void	ft_g_insert(t_gnode *node, t_gnode *next);
void	ft_g_unlink(t_gnode *a, t_gnode *b);

bool	ft_is_link(t_link *link, t_gnode *a, t_gnode *b);
bool	ft_has_link(t_gnode *a, t_gnode *b);

t_link	*ft_active_link(t_link *link);

void	dry(t_gnode **all);
int		ft_g_capacity(t_link *link, t_gnode *node);
void	ft_setflow(t_link *link, t_gnode *next);
void	ft_resetflow(t_link *link, t_gnode *next);

t_gnode	*ft_otherside(t_link *link, t_gnode *myside);

size_t	ft_active_link_size(t_gnode *node);
size_t	ft_flow_link_size(t_gnode *node);

#endif
