/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:21:03 by cdahlhof          #+#    #+#             */
/*   Updated: 2025/08/11 04:25:24 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_p_vars	**query(void)
{
	static t_p_vars	*p_vars;

	return (&p_vars);
}

int	reset_flags_extension(void)
{
	t_p_vars	*p_vars;

	p_vars = *query();
	if (p_vars)
	{
		if (p_vars->value_base)
			ft_free(p_vars->value_base);
		p_vars->value_base = NULL;
		if (p_vars->temp)
			ft_free(p_vars->temp);
		p_vars->temp = NULL;
		p_vars->string = NULL;
		p_vars->c = '\r';
	}
	else
		return (1);
	return (0);
}

int	reset_flags(void)
{
	t_p_vars	*p_vars;

	p_vars = *query();
	if (p_vars)
	{
		p_vars->do_sign = false;
		p_vars->do_width = false;
		p_vars->do_precision = false;
		p_vars->sign_positive = false;
		p_vars->is_negative = false;
		p_vars->leftbound = false;
		p_vars->padd_char = ' ';
		p_vars->pointer_prefix = false;
		p_vars->width = 0;
		p_vars->precision = 0;
		p_vars->insert_identifier = '\0';
		p_vars->value_length = 0;
	}
	else
		return (1);
	return (reset_flags_extension());
}

int	ft_init(const char *format)
{
	t_p_vars	*p_vars;

	if (format)
	{
		*query() = ft_malloc(sizeof(t_p_vars));
		ft_bzero(*query(), sizeof(t_p_vars));
		p_vars = *query();
		p_vars->format = (char *)format;
		p_vars->insert = NULL;
		p_vars->i = 0;
		p_vars->skipped = 0;
		p_vars->added = 0;
		p_vars->written = 0;
		if (reset_flags())
			return (1);
		p_vars->debug = false;
		p_vars->f = NULL;
		p_vars->fd = 0;
	}
	else
		return (1);
	return (0);
}

int	ft_close(int return_value)
{
	t_p_vars	*p_vars;

	p_vars = *query();
	if (p_vars)
	{
		if (p_vars->value_base)
			ft_free(p_vars->value_base);
		p_vars->value_base = NULL;
		if (p_vars->temp)
			ft_free(p_vars->temp);
		p_vars->temp = NULL;
		if (p_vars->string)
			ft_free(p_vars->string);
		p_vars->string = NULL;
		ft_free(p_vars);
		*query() = NULL;
	}
	return (return_value);
}
