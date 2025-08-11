/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:14:43 by cdahlhof          #+#    #+#             */
/*   Updated: 2025/08/10 03:32:58 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	handle_pointy();
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

int	handle_d_i(va_list a)
{
	t_p_vars	*p_vars;
	long		val;
	int			num;

	p_vars = *query();
	val = va_arg(a, int);
	num = val;
	if (val < 0)
	{
		p_vars->is_negative = true;
		num = -val;
	}
	p_vars->value_base = ft_strdup("0123456789");
	p_vars->value_length = ft_log((unsigned int)num, 10);
	if (num && p_vars->value_length > p_vars->precision)
		p_vars->precision = p_vars->value_length;
	if (p_vars->do_precision)
		p_vars->padd_char = ' ';
	p_vars->width -= (p_vars->do_sign || p_vars->sign_positive || \
														p_vars->is_negative);
	return (handle_padding((unsigned int)num));
}

int	handle_u(va_list a)
{
	t_p_vars		*p_vars;
	unsigned int	num;

	p_vars = *query();
	num = va_arg(a, int);
	p_vars->value_base = ft_strdup("0123456789");
	p_vars->value_length = ft_log(num, 10);
	p_vars->width -= (p_vars->do_sign || p_vars->sign_positive);
	if (num && p_vars->value_length > p_vars->precision)
		p_vars->precision = p_vars->value_length;
	if (p_vars->do_precision)
		p_vars->padd_char = ' ';
	return (handle_padding(num));
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
