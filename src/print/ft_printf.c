/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:47:42 by cdahlhof          #+#    #+#             */
/*   Updated: 2026/03/30 13:02:07 by cdahlhof         ###   ########.fr       */
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
	int			process_return;
	int			written_length;

	if (ft_init(format))
		return (0);
	va_start(a, format);
	p_vars = *query();
	process_return = sprint(a);
	written_length = p_vars->written;
	if (process_return)
		va_end(a);
	return (ft_close(written_length));
}

int	ft_printf_fd(int fd, const char *format, ...)
{
	t_p_vars	*p_vars;
	va_list		a;
	int			process_return;
	int			written_length;

	if (ft_init(format))
		return (0);
	p_vars = *query();
	p_vars->fd = fd;
	va_start(a, format);
	process_return = sprint(a);
	written_length = p_vars->written;
	if (process_return)
		va_end(a);
	return (ft_close(written_length));
}

int	ft_vfprintf(FILE *f, const char *format, va_list a)
{
	t_p_vars	*p_vars;
	int			process_return;
	int			written_length;

	if (ft_init(format))
		return (0);
	p_vars = *query();
	p_vars->debug = true;
	p_vars->f = f;
	process_return = sprint(a);
	written_length = p_vars->written;
	if (process_return)
		va_end(a);
	return (ft_close(written_length));
}

char *ft_asprintf(const char *format, ...)
{
	t_p_vars	*p_vars;
	va_list		a;
	int			process_return;
	int			written_length;
	char		*result;

	if (ft_init(format))
		return (0);
	p_vars = *query();
	p_vars->as = ft_calloc(1, 1);
	va_start(a, format);
	process_return = sprint(a);
	written_length = p_vars->written;
	if (process_return)
		va_end(a);
	result = ft_malloc(p_vars->as_written + 1);
	if (!result)
		return (ft_close(written_length), NULL);
	ft_strlcpy(result, p_vars->as, p_vars->as_written + 1);
	return (ft_close(written_length), result);
}
