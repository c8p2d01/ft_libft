/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:23:42 by cdahlhof          #+#    #+#             */
/*   Updated: 2025/08/09 20:08:36 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_putnbr_base_fd(unsigned int num, char *base, int fd)
{
	int	i;

	i = 1;
	if (num >= ft_strlen(base))
		i += ft_putnbr_base_fd(num / ft_strlen(base), base, fd);
	write(fd, &(base[(num % ft_strlen(base))]), 1);
	return (i);
}

int	print_base(char *base, unsigned long nbr)
{
	int	i;
	int	error;
	int	baselen;

	i = 0;
	baselen = ft_strlen(base);
	if (!baselen)
		base = "0123456789";
	if (nbr >= (unsigned long)ft_strlen(base))
	{
		error = print_base(base, nbr / ft_strlen(base));
		if (error < 0)
			return (-1);
		i += error;
	}
	error = ft_printchar(base[(nbr % ft_strlen(base))]);
	if (error < 0)
		return (-1);
	return (error + i);
}

/**
 * ALERT this function is highly unsstable and relies
 * on the memory to be allocated and iterates starting in the end
 */
void	print_base_to_mem(char *dest, char *base, unsigned long nbr)
{
	int	baselen;

	baselen = ft_strlen(base);
	if (!baselen)
		base = "0123456789";
	if (nbr >= (unsigned long)ft_strlen(base))
	{
		print_base_to_mem(dest - 1, base, nbr / ft_strlen(base));
	}
	*dest = base[(nbr % ft_strlen(base))];
}
