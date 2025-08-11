/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:13:42 by cdahlhof          #+#    #+#             */
/*   Updated: 2025/08/10 03:32:31 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_pad(unsigned long num)
{
	t_p_vars	*p_vars;
	int			pad;

	p_vars = *query();
	pad = 0;
	if (num || !p_vars->do_precision)
		pad = p_vars->value_length;
	if (p_vars->precision > pad)
		pad = p_vars->precision;
	if (p_vars->width > pad)
		pad = p_vars->width;
	if (pad && p_vars->precision == 0 && p_vars->do_precision == true && \
													p_vars->do_width == false)
		pad--;
	if (p_vars->is_negative || p_vars->do_sign || p_vars->sign_positive)
		pad++;
	if (p_vars->pointer_prefix)
		pad += 2;
	p_vars->temp = malloc(pad + 1);
	ft_memset(p_vars->temp, '@', pad + 1);
	p_vars->temp[pad] = '\0';
	if ((p_vars->do_precision && p_vars->precision) || !p_vars->do_precision)
		print_base_to_mem(p_vars->temp + pad - 1, p_vars->value_base, num);
	p_vars->pad = pad;
}

void	handle_precision(void)
{
	t_p_vars	*p_vars;

	p_vars = *query();
	while (p_vars->p_i < p_vars->precision)
	{
		*ft_strrchr(p_vars->temp, '@') = '0';
		p_vars->p_i++;
	}
	while (p_vars->p_i < p_vars->width && p_vars->padd_char == '0')
	{
		*ft_strrchr(p_vars->temp, '@') = '0';
		p_vars->p_i++;
	}
}

void	handle_sign(void)
{
	t_p_vars	*p_vars;

	p_vars = *query();
	if (p_vars->is_negative && !p_vars->pointer_prefix)
	{
		*ft_strrchr(p_vars->temp, '@') = '-';
		p_vars->p_i++;
	}
	else if (p_vars->sign_positive && !p_vars->pointer_prefix)
	{
		*ft_strrchr(p_vars->temp, '@') = '+';
		p_vars->p_i++;
	}
	else if (p_vars->do_sign && !p_vars->pointer_prefix)
	{
		*ft_strrchr(p_vars->temp, '@') = ' ';
		p_vars->p_i++;
	}
}

void	handle_pointy(void)
{
	t_p_vars	*p_vars;

	p_vars = *query();
	if (p_vars->pointer_prefix && ft_strchr("pxX", p_vars->insert_identifier))
	{
		if (p_vars->insert_identifier == 'X')
			*ft_strrchr(p_vars->temp, '@') = 'X';
		else
			*ft_strrchr(p_vars->temp, '@') = 'x';
		p_vars->p_i++;
		*ft_strrchr(p_vars->temp, '@') = '0';
		p_vars->p_i++;
	}
}

void	handle_leftsbound(void)
{
	t_p_vars	*p_vars;

	p_vars = *query();
	if (p_vars->leftbound && p_vars->p_i < p_vars->pad)
	{
		ft_memcpy(p_vars->temp, ft_strrchr(p_vars->temp, '@') + 1, \
								ft_strlen(ft_strrchr(p_vars->temp, '@') + 1));
		while (p_vars->p_i < p_vars->pad)
		{
			p_vars->temp[p_vars->p_i] = ' ';
			p_vars->p_i++;
		}
	}
}
