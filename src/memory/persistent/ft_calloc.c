#include "../ft_memory.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dest;

	dest = (void *)ft_malloc(nmemb * size);
	if (!dest)
		return (NULL);
	ft_bzero(dest, nmemb * size);
	return (dest);
}
