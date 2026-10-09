#include "../ft_print.h"

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
	p_vars->value_length = ft_count_digit((unsigned int)num, 10);
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
	p_vars->value_length = ft_count_digit(num, 10);
	p_vars->width -= (p_vars->do_sign || p_vars->sign_positive);
	if (num && p_vars->value_length > p_vars->precision)
		p_vars->precision = p_vars->value_length;
	if (p_vars->do_precision)
		p_vars->padd_char = ' ';
	return (handle_padding(num));
}
