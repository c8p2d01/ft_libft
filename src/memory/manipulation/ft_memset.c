#include "../ft_memory.h"

/**
 * @brief set n  bytes of s to value c
 */
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*d;
	size_t			i;

	i = 0;
	d = (unsigned char *)s;
	while (n > i)
	{
		d[i] = c;
		i++;
	}
	return (s);
}
