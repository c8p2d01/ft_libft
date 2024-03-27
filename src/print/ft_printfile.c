#include "../../inc/libft.h"

void	printfile(int fd)
{
	char	*line;

	line = ft_get_next_line(fd);
	while (line)
	{
		printf("%s\n", line);
		free (line);
		line = ft_get_next_line(fd);
	}
}
