#include "ft_read.h"

/**
 * @brief attempt to open a file
 */
int		open_file(char *path)
{
	t_list	*i;
	t_file	*f;

	i = *opened_files();
	if (!i)
	{
		f = ft_malloc(sizeof(t_file));
		f->path = ft_strdup(path);
		f->fd = open(f->path, O_RDWR | O_APPEND, S_IRUSR | S_IWUSR);
		f->buffer = ft_calloc(1, BUFFER_SIZE + 1);
		i = ft_lstnew(f);
		*opened_files() = i;
	}
	while (i)
	{
		f = i->content;
		if (!ft_strcmp(path, f->path))
			return(f->fd);
		i = i->next;
	}
	return (-1);
}

/**
 * @brief return the buffer used for reading from a file
 * if file wasnt opened with out own function then a shared bufffer is used.
 * → may break multi file reading
 */
char	*get_buffer(int fd)
{
	t_list		*i;
	t_file		*f;
	static char	error_buffer[BUFFER_SIZE + 1];

	i = *opened_files();
	if (!i)
	{
		// this shouldnt occur
		return (error_buffer);
	}
	while (i)
	{
		f = i->content;
		if (fd == f->fd)
			return(f->buffer);
		i = i->next;
	}
	return (error_buffer);
}
