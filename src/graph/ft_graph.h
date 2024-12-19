/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:41:07 by cdahlhof          #+#    #+#             */
/*   Updated: 2024/12/19 21:28:24 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GRAPH_H
# define FT_GRAPH_H

# define FLOW_ERROR 255

# include "../../inc/libft.h"

typedef struct s_graph
{
	void			*content;
	struct s_list	*links;
}	t_graph;

typedef struct s_link
{
	struct s_graph	*from;
	struct s_graph	*to;
	void			*info;
}	t_link;

t_graph	*ft_new_graph(void *content);

void	ft_cut_graph(t_graph *node, void (*del)(void*));

void	ft_rip_graph(t_graph *node, void (*del)(void*));

t_link	*ft_new_link(t_graph *in, t_graph *out, void *info);

void	ft_link_nodes(t_graph *node, t_graph *next, \
										void *(*info)(t_graph *, t_graph *));

bool	ft_is_link(t_link *link, t_graph *a, t_graph *b);

bool	ft_has_link(t_graph *a, t_graph *b);

void	ft_unlink(t_graph *node, t_graph *next);

t_graph	*ft_otherside(t_link *link, t_graph *myside);

#endif
