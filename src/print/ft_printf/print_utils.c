/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:10:38 by cdahlhof          #+#    #+#             */
/*   Updated: 2025/08/10 03:41:13 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c)
{
	t_p_vars	*p_vars;

	p_vars = *query();
	if (p_vars->f)
	{
		if (fwrite(&c, 1, 1, p_vars->f) != 1)
			return (0);
	}
	else if (p_vars->fd > 0)
	{
		if (write(p_vars->fd, &c, 1))
			return (0);
	}
	else
	{
		if (write(1, &c, 1) != 1)
			return (0);
	}
	p_vars->written++;
	return (1);
}

int	repeat_char(char c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (!ft_printchar(c))
			return (0);
		i++;
	}
	return (1);
}
