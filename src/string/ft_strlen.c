/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:43:14 by cdahlhof          #+#    #+#             */
/*   Updated: 2024/03/14 20:16:17 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

/**
 * @brief Get 2D array size
 */
size_t	ft_array_size(void **array)
{
	size_t	i;

	i = 0;
	while (array && array[i])
		i++;
	return (i);
}

#ifdef TEST

int main(int argc, char **argv)
{
	(void)argc;
	{
		char	*s = "Hello World!";
		size_t	mine = ft_strlen(s);
		int	compare = strlen(s);
		if (mine == compare)
			printf("[✓]\ttest: <%s>", s);
		else
			printf("[✘]\ttest: <%s>\n\tmine: <%lu>\n\toriginal: <%i>\n", s, mine, compare);
	}
}

#endif

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!str)
// 		return 0;
// 	while (str && str[i] != '\0')
// 		i++;
// 	return (i);
// }
