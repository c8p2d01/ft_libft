/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2d_array_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:41:25 by cdahlhof          #+#    #+#             */
/*   Updated: 2024/03/27 08:15:47 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_2d_array_size(void **arr)
{
	int32_t	i;

	i = 0;
	while (arr[i] != NULL)
	{
		i++;
	}
	return (i);
}

#ifdef TEST

int main(int argc, char **argv)
{
	(void)argc;
	printf("testing file %s\n", argv[0]);

	{
		char	**s = malloc(4 * sizeof(char *));
		if (!s)
			exit(1);
		s[0] = "null";
		s[1] = "";
		s[2] = "NULL";
		s[3] = NULL;
		if (ft_2d_array_size((void **)s) == 3)
			printf("[✓]\n");
		else
			printf("[✘]\n");
		free(s);
	}
}

#endif
