#include "../ft_list.h"

/**
 * @brief compare lists a and b on having the exact same content pointers
 */
bool	ft_lst_iseq(t_list *a, t_list *b)
{
	if (a == b || \
		a->content == b->content)
		return (true);
	return (false);
}
