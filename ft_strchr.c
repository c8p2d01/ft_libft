/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 12:41:01 by clems             #+#    #+#             */
/*   Updated: 2022/07/16 20:37:45 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// return a pointer to the first instance of c in str
char	*ft_strchr(const char *str, int c)
{
	return (ft_memchr(str, c, ft_strlen(str) + 1));
}
//int main()
//{
//		char	satz[] = "abcdefghijklmnopqrstuvwxyz0123456789";
//	char	*pc;
//	char	c = 'h';
//	pc = ft_strchr(satz, c, 36);
//	write(1, &c, 1);
//	write(1, "\t", 1);
//	write(1, pc, 10);
//	/*
//	in the test i write 10 chars from the result onwars to prove the first 
//	one was found. if this leads to a seg fault in testing the function
//	is not stupid, the tester is ,_,
//	or i am for not using printf lol
//	*/
//}
