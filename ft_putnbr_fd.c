/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 14:27:59 by clems             #+#    #+#             */
/*   Updated: 2022/07/16 20:37:57 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// write an integer to a given file-directory
int	ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		d;

	d = 0;
	if (n == -2147483648)
		d = write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			d += write(fd, "-", 1);
			n = -n;
		}
		if (n >= 10)
			ft_putnbr_fd(n / 10, fd);
		c = (n % 10) + 48;
		d += write(fd, &c, 1);
	}
	return (d);
}
// int main()
// {
// 	int i = 1;
// 	while (i < 50)
// 	{
// 		ft_putnbr_fd((i % 10), 1);write(1, " ", 1);i++;
// 		ft_putnbr_fd((i % 10), 1);write(1, " ", 1);i++;
// 		ft_putnbr_fd((i % 10), 1);write(1, " ", 1);i++;
// 		ft_putnbr_fd((i % 10), 1);write(1, " ", 1);i++;
// 		ft_putnbr_fd((i % 10), 1);write(1, " ", 1);i -= 4;
// 		ft_putnbr_fd((i % 10) + 10, 1);write(1, " ", 1);i++;
// 		ft_putnbr_fd((i % 10) + 10, 1);write(1, " ", 1);i++;
// 		ft_putnbr_fd((i % 10) + 10, 1);write(1, " ", 1);i++;
// 		ft_putnbr_fd((i % 10) + 10, 1);write(1, " ", 1);i++;
// 		ft_putnbr_fd((i % 10) + 10, 1);write(1, " ", 1);i++;
// 	}
// 	ft_putnbr_fd(50, 1);
// }
