/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_reading.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:17:07 by cdahlhof          #+#    #+#             */
/*   Updated: 2025/08/10 03:32:17 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	read_flags(void)
{
	t_p_vars	*p_vars;

	p_vars = *query();
	if (p_vars->format[p_vars->i + p_vars->len] == ' ')
		p_vars->do_sign = true;
	if (p_vars->format[p_vars->i + p_vars->len] == '+')
		p_vars->sign_positive = true;
	if (p_vars->format[p_vars->i + p_vars->len] == '-')
		p_vars->leftbound = true;
	if (p_vars->format[p_vars->i + p_vars->len] == '#')
		p_vars->pointer_prefix = true;
	if (p_vars->format[p_vars->i + p_vars->len] == '0')
		p_vars->padd_char = '0';
}

void	read_numbers(void)
{
	t_p_vars	*p_vars;

	p_vars = *query();
	if (p_vars->format[p_vars->i + p_vars->len] == '.')
	{
		p_vars->precision = \
						ft_atoi(&p_vars->format[p_vars->i + p_vars->len + 1]);
		if (p_vars->precision != 0)
			p_vars->add += ft_log(p_vars->precision, 10);
		if (p_vars->format[p_vars->i + p_vars->len + 1] == '0')
			p_vars->add++;
		p_vars->do_precision = true;
	}
	if (ft_strchr("123456789", p_vars->format[p_vars->i + p_vars->len]))
	{
		p_vars->do_width = true;
		p_vars->width = ft_atoi(&p_vars->format[p_vars->i + p_vars->len]);
		p_vars->add = ft_log(p_vars->width, 10);
	}
}

int	delegate_handlers(va_list a)
{
	t_p_vars	*p_vars;

	p_vars = *query();
	if (p_vars->insert_identifier == 'i' || p_vars->insert_identifier == 'd')
		return (handle_d_i(a));
	if (p_vars->insert_identifier == 'u')
		return (handle_u(a));
	if (p_vars->insert_identifier == 'x')
		return (handle_x(a));
	if (p_vars->insert_identifier == 'p')
		return (handle_p(a));
	if (p_vars->insert_identifier == 'X')
		return (handle_big_x(a));
	if (p_vars->insert_identifier == 'c')
		return (handle_c(a));
	if (p_vars->insert_identifier == '%')
		return (handle_percent());
	if (p_vars->insert_identifier == 's')
		return (handle_s(a));
	return (0);
}

int	trigger_insert(va_list a)
{
	t_p_vars	*p_vars;

	p_vars = *query();
	p_vars->len = 0;
	while (p_vars->format[p_vars->i + p_vars->len] && \
			!ft_strchr("discuxXp%", p_vars->format[p_vars->i + p_vars->len]))
	{
		p_vars->add = 1;
		read_flags();
		read_numbers();
		p_vars->len += p_vars->add;
	}
	if (p_vars->format[p_vars->i + p_vars->len])
		p_vars->insert_identifier = \
			*ft_strchr("discuxXp%", p_vars->format[p_vars->i + p_vars->len]);
	p_vars->skipped = p_vars->len + 1;
	delegate_handlers(a);
	reset_flags();
	return (0);
}
