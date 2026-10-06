#include "../ft_memory.h"

void	*ft_realloc(void *old, size_t old_len, size_t add_len)
{
	char	*new;

	new = ft_calloc(old_len + add_len, 1);
	ft_memcpy(new, old, old_len);
	if (old)
		ft_free(old);
	return ((void *)new);
}
