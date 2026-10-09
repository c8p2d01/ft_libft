#include "../ft_graph.h"

/**
 * @brief Allocate a new node
 */
t_net	*ft_new_net()
{
	t_net *res;

	res = ft_malloc(sizeof(t_net));
	if (res == NULL)
		return (NULL);
	*res = (t_net){
		.graph_nodes = NULL,
		.graph_links = NULL,
		.content     = NULL
	};
	return (res);
}
