#include "../ft_print.h"

int	ft_printchar(char c)
{
	t_p_vars	*p_vars;

	p_vars = *query();
	if (p_vars->f)
	{
		if (fwrite(&c, 1, 1, p_vars->f) != 1)
			return (0);
	}
	else if(p_vars->as)
	{
		if (p_vars->as_remaining <= 0)
		{
			p_vars->as_remaining = ALLOCATION_SIZE;
			p_vars->as = ft_realloc(p_vars->as, ft_strlen(p_vars->as), ALLOCATION_SIZE);
			if (!p_vars->as)
				return (0);
		}
		p_vars->as[p_vars->as_written] = c;
		p_vars->as_written++;
		p_vars->as_remaining--;
	}
	else if (p_vars->fd > 0)
	{
		if (write(p_vars->fd, &c, 1))
			return (0);
	}
	else
	{
		if (write(1, &c, 1) != 1)
			return (0);
	}
	p_vars->written++;
	return (1);
}

int	repeat_char(char c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (!ft_printchar(c))
			return (0);
		i++;
	}
	return (1);
}
