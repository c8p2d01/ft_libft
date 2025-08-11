/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:16:00 by cdahlhof          #+#    #+#             */
/*   Updated: 2025/08/10 03:28:53 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_c(va_list a)
{
	t_p_vars	*p_vars;
	char		c;

	p_vars = *query();
	c = va_arg(a, int);
	p_vars->value_length = 1;
	p_vars->do_precision = false;
	p_vars->c = c;
	p_vars->width--;
	return (char_padding());
}

#if __APPLE__

int	handle_s(va_list a)
{
	t_p_vars	*p_vars;
	char		*s;

	p_vars = *query();
	s = va_arg(a, char *);
	if (!s)
	{
		p_vars->value_base = ft_strdup("(null)");
		s = p_vars->value_base;
	}
	p_vars->value_length = ft_strlen(s);
	p_vars->string = s;
	if (p_vars->precision > p_vars->value_length && s)
		p_vars->precision = p_vars->value_length;
	if (!s && !p_vars->do_precision)
		p_vars->precision = 6;
	return (string_padding());
}

#else

int	handle_s(va_list a)
{
	t_p_vars	*p_vars;
	char		*s;

	p_vars = *query();
	s = va_arg(a, char *);
	if (!s)
	{
		if (p_vars->precision > 6 || !p_vars->do_precision)
			p_vars->value_base = ft_strdup("(null)");
		else
			p_vars->value_base = ft_strdup("");
		s = p_vars->value_base;
	}
	p_vars->value_length = ft_strlen(s);
	p_vars->string = s;
	if (p_vars->precision > p_vars->value_length && s)
		p_vars->precision = p_vars->value_length;
	if (!s && !p_vars->do_precision)
		p_vars->precision = 6;
	return (string_padding());
}
#endif
