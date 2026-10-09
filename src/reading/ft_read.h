#ifndef FT_READ_H
# define FT_READ_H

# include <fcntl.h>
# include "../../inc/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef struct	s_file
{
    char	*path;
	int		fd;
	char	*buffer;
}	t_file;

int		open_file(char *path);
char	*get_buffer(int fd);

char	*get_next_line(int fd);

char	*get_until(int fd, char d);

#endif