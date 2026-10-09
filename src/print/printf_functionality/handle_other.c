#include "../ft_print.h"

int	handle_padding(unsigned long num)
{
	t_p_vars	*p_vars;
	int			i;

	p_vars = *query();
	set_pad(num);
	p_vars->p_i = p_vars->value_length;
	handle_precision();
	handle_sign();
	i = p_vars->p_i;
	handle_pointers();
	handle_leftsbound();
	i = 0;
	while (p_vars->temp && p_vars->temp[i])
	{
		if (p_vars->temp[i] == '@')
			p_vars->temp[i] = ' ';
		if (!ft_printchar(p_vars->temp[i]))
			return (0);
		i++;
	}
	return (1);
}

int	handle_percent(void)
{
	t_p_vars	*p_vars;

	p_vars = *query();
	p_vars->value_length = 1;
	p_vars->do_precision = false;
	p_vars->c = '%';
	p_vars->width--;
	return (char_padding());
}
