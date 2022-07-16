/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:19:55 by clems             #+#    #+#             */
/*   Updated: 2022/07/16 20:38:07 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// write a given char to a given file-directory
int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}
//int main()
//{
//	ft_putchar_fd('a', 1);
//}
