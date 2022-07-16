/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_rand.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 15:28:48 by cdahlhof          #+#    #+#             */
/*   Updated: 2022/07/16 20:27:44 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	a fuction that gets a maximum and an amount as input
//	and gives amount many random, non duplicate numbers as output
//	invalid input is not yet handled

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	dupes(char **nums);

int	main(int argc, char **argv)
{
	int		i;
	char	**nums;

	i = 0;
	nums = (char **)ft_calloc(ft_atoi(argv[2]) + 1, sizeof(char *));
	if (argc != 3)
		return (0);
	while (i < ft_atoi(argv[2]))
	{
		nums[i] = ft_itoa(rand() % ft_atoi(argv[1]));
		if (dupes(nums) != 0)
			continue ;
		ft_putstr_fd(nums[i]);
		write(1, " ", 1);
		i++;
	}
	free(nums);
}

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
		while (s < l && (ft_atoi(nums[i]) != ft_atoi(nums[s])))
			s++;
		if (s != l)
			return (1);
		i++;
	}
	return (0);
}
