/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 20:40:42 by cdahlhof          #+#    #+#             */
/*   Updated: 2022/07/16 20:39:13 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//🌊

// check if the given char is part of either standart alphabet
int	ft_isalpha(int c)
{
	if ((('A' <= c) && (c <= 'Z')) || (('a' <= c) && (c <= 'z')))
		return (1024);
	return (0);
}
