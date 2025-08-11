/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:12:37 by cdahlhof          #+#    #+#             */
/*   Updated: 2025/08/10 03:27:38 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	string_padding_continuance(void)
{
	t_p_vars	*p_vars;
	int			i;

	p_vars = *query();
	i = 0;
	while (p_vars->string && p_vars->string[i] && \
			(p_vars->precision > i || !p_vars->do_precision))
	{
		if (!ft_printchar(p_vars->string[i]))
			return (0);
		i++;
	}
	if (p_vars->leftbound && (p_vars->width > i))
	{
		if (!repeat_char(' ', p_vars->width - i))
			return (0);
	}
	return (1);
}

int	string_padding(void)
{
	t_p_vars	*p_vars;

	p_vars = *query();
	if (!p_vars->leftbound)
	{
		if (p_vars->do_precision && (p_vars->width > p_vars->precision))
		{
			if (!repeat_char(p_vars->padd_char, \
											p_vars->width - p_vars->precision))
				return (0);
		}
		else if (!p_vars->do_precision && \
										(p_vars->width > p_vars->value_length))
		{
			if (!repeat_char(p_vars->padd_char, \
										p_vars->width - p_vars->value_length))
				return (0);
		}
	}
	string_padding_continuance();
	return (1);
}

int	char_padding_extension(void)
{
	t_p_vars	*p_vars;

	p_vars = *query();
	if (p_vars->do_precision && p_vars->precision > p_vars->value_length)
	{
		if (p_vars->is_negative)
		{
			ft_printchar('-');
			p_vars->is_negative = false;
		}
		if (!repeat_char('0', p_vars->precision - p_vars->value_length))
			return (0);
	}
	if (p_vars->is_negative)
		ft_printchar('-');
	else if (p_vars->insert_identifier == 'c' || \
				p_vars->insert_identifier == '%')
		ft_printchar(p_vars->c);
	if (p_vars->leftbound && p_vars->do_width && \
										(p_vars->width > p_vars->precision))
	{
		if (!repeat_char(' ', p_vars->width - p_vars->precision))
			return (0);
	}
	return (1);
}

int	char_padding(void)
{
	t_p_vars	*p_vars;

	p_vars = *query();
	if (!p_vars->leftbound && p_vars->do_width && \
											(p_vars->width > p_vars->precision))
	{
		if (p_vars->padd_char == '0' && p_vars->is_negative)
		{
			ft_printchar('-');
			p_vars->is_negative = false;
		}
		if (!repeat_char(p_vars->padd_char, p_vars->width - p_vars->precision))
			return (0);
	}
	char_padding_extension();
	return (1);
}
