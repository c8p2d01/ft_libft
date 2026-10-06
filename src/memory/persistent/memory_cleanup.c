#include "../ft_memory.h"

/**
 * @brief clear all allocated memory and exit
 */
int	allocation_error(void)
{
	ft_clean_allocs();
	exit(1);
}

/**
 * @brief close files listed as openend
 */
void	ft_clean_fds(void)
{
	t_list	*i;
	t_file	*f;

	i = *opened_files();
	while (i)
	{
		f = i->content;
		close(f->fd);
		ft_free(f->path);
		i = i->next;
	}
}

/**
 * @brief free all block of memory still in the list
 */
void	ft_clean_allocs(void)
{
	t_list	*l;
	t_list	*t;

	l = *memory();
	while (l)
	{
		t = l->next;
		if (l->content)
		{
			ft_free(l->content);
		}
		l = t;
	}
	l = *memory();
	ft_lstclear(&l, free);
	*memory() = NULL;
}