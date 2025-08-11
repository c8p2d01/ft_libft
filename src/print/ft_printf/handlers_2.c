/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:16:00 by cdahlhof          #+#    #+#             */
/*   Updated: 2025/08/10 03:30:50 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_x(va_list a)
{
	t_p_vars			*p_vars;
	unsigned int		num;

	p_vars = *query();
	num = va_arg(a, int);
	if (!num)
		p_vars->pointer_prefix = false;
	p_vars->value_base = ft_strdup("0123456789abcdef");
	p_vars->value_length = ft_log(num, 16);
	if (p_vars->do_precision)
		p_vars->padd_char = ' ';
	if (num && p_vars->value_length > p_vars->precision)
		p_vars->precision = p_vars->value_length;
	p_vars->width -= (p_vars->do_sign || p_vars->sign_positive);
	if (num && p_vars->pointer_prefix)
		p_vars->width -= 2;
	return (handle_padding(num));
}

int	handle_big_x(va_list a)
{
	t_p_vars			*p_vars;
	unsigned int		num;

	p_vars = *query();
	num = va_arg(a, int);
	if (!num)
		p_vars->pointer_prefix = false;
	p_vars->value_base = ft_strdup("0123456789ABCDEF");
	p_vars->value_length = ft_log(num, 16);
	if (p_vars->do_precision)
		p_vars->padd_char = ' ';
	if (num && p_vars->value_length > p_vars->precision)
		p_vars->precision = p_vars->value_length;
	p_vars->width -= (p_vars->do_sign || p_vars->sign_positive);
	if (num && p_vars->pointer_prefix)
		p_vars->width -= 2;
	return (handle_padding(num));
}

#if __APPLE__

int	handle_p(va_list a)
{
	t_p_vars			*p_vars;
	unsigned long		num;

	p_vars = *query();
	num = va_arg(a, unsigned long);
	p_vars->do_width = false;
	p_vars->width -= 2;
	p_vars->pointer_prefix = true;
	p_vars->value_base = ft_strdup("0123456789abcdef");
	p_vars->value_length = ft_log(num, 16);
	if (p_vars->value_length > p_vars->precision)
		p_vars->precision = p_vars->value_length;
	p_vars->width -= (p_vars->do_sign || p_vars->sign_positive);
	return (handle_padding(num));
}

#else

int	handle_p(va_list a)
{
	t_p_vars		*p_vars;
	unsigned long	num;

	p_vars = *query();
	num = va_arg(a, unsigned long);
	if (num)
	{
		p_vars->do_width = false;
		p_vars->width -= 2;
		p_vars->pointer_prefix = true;
		p_vars->value_base = ft_strdup("0123456789abcdef");
		p_vars->value_length = ft_log(num, 16);
		if (p_vars->value_length > p_vars->precision)
			p_vars->precision = p_vars->value_length;
		p_vars->width -= (p_vars->do_sign || p_vars->sign_positive);
		handle_padding(num);
	}
	else
	{
		p_vars->do_precision = false;
		p_vars->string = ft_strdup("(nil)");
		string_padding();
	}
	return (0);
}

#endif
