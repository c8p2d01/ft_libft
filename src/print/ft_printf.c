/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:47:42 by cdahlhof          #+#    #+#             */
/*   Updated: 2025/08/11 04:29:54 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	sprint(va_list a)
{
	t_p_vars	*p_vars;
	int			i;

	p_vars = *query();
	i = 0;
	while (p_vars->format[i])
	{
		p_vars = *query();
		if (p_vars->format[i] != '%')
		{
			if (ft_printchar(p_vars->format[i]) != 1)
				return (1);
		}
		else
		{
			p_vars->i = i + 1;
			if (trigger_insert(a))
				return (1);
			p_vars = *query();
			i += p_vars->skipped;
		}
		i++;
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	t_p_vars	*p_vars;
	va_list		a;

	if (ft_init(format))
		return (0);
	va_start(a, format);
	p_vars = *query();
	if (!sprint(a))
		return (ft_close(p_vars->written));
	va_end(a);
	ft_close(p_vars->written);
	return (p_vars->written);
}

int	ft_printf_fd(int fd, const char *format, ...)
{
	t_p_vars	*p_vars;
	va_list		a;

	if (ft_init(format))
		return (0);
	p_vars = *query();
	p_vars->fd = fd;
	va_start(a, format);
	if (!sprint(a))
		return (ft_close(p_vars->written));
	va_end(a);
	return (ft_close(p_vars->written));
}

int	ft_vfprintf(FILE *f, const char *format, va_list a)
{
	t_p_vars	*p_vars;

	if (ft_init(format))
		return (0);
	p_vars = *query();
	p_vars->debug = true;
	p_vars->f = f;
	sprint(a);
	return (ft_close(p_vars->written));
}
