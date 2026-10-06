#include "../ft_memory.h"

/**
 * frees each of *s and then s
 * @param s [char **]
 * @return [int] 0
*/
int	free_2dstr(char **s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		ft_free(s[i]);
		i ++;
	}
	ft_free(s);
	return (0);
}

void	unreach(void *freeMe)
{
	ft_free(freeMe);
	freeMe = NULL;
}
