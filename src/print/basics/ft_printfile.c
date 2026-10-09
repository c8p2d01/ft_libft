#include "../ft_print.h"

void	printfile(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		printf("%s\n", line);
		ft_free (line);
		line = get_next_line(fd);
	}
}
