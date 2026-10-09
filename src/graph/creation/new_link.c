#include "../ft_graph.h"

/**
 * @brief Allocate new link
 */
t_link	*ft_new_link(t_graph *in, t_graph *out)
{
	t_link	*res;
	t_list	*list;
	t_net	*net;

	res = ft_malloc(sizeof(t_link));
	if (!res)
		return (NULL);
	*res = (t_link){
		.from = in,
		.to = out,
		.active = false,
		.direction = 0
	};
	net = *catch();
	list = ft_lstnew(res);
	ft_lstadd_back(&(net->graph_links), list);
	return (res);
}
