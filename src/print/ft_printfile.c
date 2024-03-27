#include "../../inc/libft.h"

void	printfile(int fd)
{
	char	*line;
	int		c;

	c = ft_get_next_line(fd, &line);
	line = NULL;
	while (c == 1)
	{
		printf("%s\n", line);
		free (line);
		c = ft_get_next_line(fd, &line);
	}
}
