#include "../ft_memory.h"

// List Head for all malloc calls
t_list	**memory(void)
{
	static t_list	*mem;

	return (&mem);
}

// List Head for malloced blocks held back from freeing
t_list	**storage_pools()
{
	static t_list	*pools;

	return (&pools);
}

// List Head for openend files
t_list	**opened_files()
{
	static t_list	*files;

	return (&files);
}

// persistent struct for my printf
t_p_vars	**query(void)
{
	static t_p_vars	*p_vars;

	return (&p_vars);
}

// persistent struct for graph nodes
t_net	**catch()
{
	static t_net	*net;

	if (!net)
		net = ft_new_net();

	return(&net);
}
