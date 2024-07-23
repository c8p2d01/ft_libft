/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_cmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:41:47 by cdahlhof          #+#    #+#             */
/*   Updated: 2024/04/13 20:51:51 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

bool	ft_lst_iseq(t_list *a, t_list *b)
{
	if (a == b || \
		a->content == b->content)
		return(true);
	return (false);
}
