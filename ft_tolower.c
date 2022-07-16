/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 10:40:42 by cdahlhof          #+#    #+#             */
/*   Updated: 2022/07/16 20:36:41 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//🌊

int	ft_tolower(int c)
{
	if (65 <= c && c <= 90)
		return (c + 32);
	return (c);
}
//#include <stdio.h>
//int main()
//{
//	char	c[] = {'a','I','T','e','4','K'};
//	printf("%s\n", c);
//	for(int i = 0; i < 6; i++)
//		c[i] = ft_tolower(c[i]);
//	printf("%s\n", c);
//}
