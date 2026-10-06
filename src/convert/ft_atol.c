/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:41:12 by cdahlhof          #+#    #+#             */
/*   Updated: 2025/10/10 13:29:42 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

long	ft_atol(const char *nptr)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	sign = 1;
	num = 0;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + nptr[i] - '0';
		i++;
	}
	return (num * sign);
}

#ifdef TEST

int main(int argc, char **argv)
{
	(void)argc;
	printf("i lay at %s\n", argv[0]);

	{
		char	*s = "42";
		long	mine = ft_atol(s);
		long	compare = atol(s);
		if (mine == compare)
			printf("[✓]\ttest: <%s>", s);
		else
			printf("[✘]\ttest: <%s>\n\tmine: <%li>\n\toriginal: <%li>\n", s, mine, compare);
	}
}

#endif
