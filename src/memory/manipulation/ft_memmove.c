#include "../ft_memory.h"

/**
 * @brief copy from src to dest until n bytes were copied, memory overlap of src and dest handeled
 * (still unsafe on access of memory...)
 */
void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*pdst;
	unsigned char	*psrc;

	if (!src && !dst)
		return (dst);
	psrc = (unsigned char *) src;
	pdst = (unsigned char *) dst;
	if (dst < src)
		dst = ft_memcpy(dst, src, n);
	else
	{
		i = 0;
		while (n > i)
		{
			pdst[n - i - 1] = psrc[n - i - 1];
			i++;
		}
	}
	return ((void *) dst);
}
