#include "../ft_graph.h"

/**
 * @brief Allocate a new node
 */
t_graph	*ft_new_graph(char *name, int x, int y)
{
	t_graph	*res;
	t_list	*list;
	t_net	*net;

	res = ft_malloc(sizeof(t_graph));
	if (res == NULL)
		return (NULL);
	*res = (t_graph){
		.links = NULL,
		.name = name,
		.pos.x = x,
		.pos.y = y,
		.force.x = 0,
		.force.y = 0,
		.velocity.x = 0,
		.velocity.y = 0,
		.content = NULL
	};
	net = *catch();
	list = ft_lstnew(res);
	ft_lstadd_back(&(net->graph_nodes), list);
	return (res);
}
