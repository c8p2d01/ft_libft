/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_randnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 23:46:57 by cdahlhof          #+#    #+#             */
/*   Updated: 2021/08/31 00:19:34 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	dupes(char **nums)
{
	int	i;
	int	s;
	int	l;

	l = 0;
	while (nums[l])
		l++;
	i = 0;
	while (l > i + 1)
	{
		s = i + 1;
		while(s < l && (ft_atoi(nums[i]) != ft_atoi(nums[s])))
			s++;
		if (s != l)
			return (1);
		i++;
	}
	return (0);
}

char	**ft_randnbr(int max, int amount)
{
	int		i;
	char	**nums;

	i = 0;
	nums = (char **)ft_calloc(amount + 1, sizeof(char *));
	while (i < amount)
	{
		nums[i] = ft_itoa(rand() % max);
		if (dupes(nums) != 0)
			continue ;
		ft_putstr_fd(nums[i], 1);
		write(1, " ", 1);
		i++;
	}
	return (nums);
}
