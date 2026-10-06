#include "../ft_memory.h"

/**
 * @brief copy from src to dest until n bytes were copied (unsafe)
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	i = 0;
	if (!dest && !src)
		return (NULL);
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	while (n > i)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
