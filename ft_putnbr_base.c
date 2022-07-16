/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:00:58 by cdahlhof          #+#    #+#             */
/*   Updated: 2022/07/16 20:38:02 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base(unsigned int num, char *base)
{
	int	i;

	i = 0;
	if (num > ft_strlen(base))
		i += ft_putnbr_base(num / ft_strlen(base), base);
	write(1, &(base[(num % ft_strlen(base))]), 1);
	return (i);
}
