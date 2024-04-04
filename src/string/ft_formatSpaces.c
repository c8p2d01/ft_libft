/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatSpaces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:42:56 by cdahlhof          #+#    #+#             */
/*   Updated: 2024/04/04 18:01:22 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/**
 * trim spaces between words down to one
 * @param s [char const *] char * to be split
 * @return [char *] shortet array
*/
void	ft_format_spaces(char *s)
{
	int		cp_from;
	int		cp_to;
	int		len;

	if (!s)
		return ;
	len = ft_strlen(s);
	cp_from = 0;
	cp_to = 0;
	while (s[cp_from] && cp_from < len)
	{
		while (ft_strchr("\t\n\v\f\r ", s[cp_from]))
			cp_from++;
		s[cp_to] = s[cp_from];
		cp_from++;
		cp_to++;
		if (ft_strchr("\t\n\v\f\r ", s[cp_from]))
			s[cp_to++] = ' ';
	}
	if (cp_to > 2)
		s[cp_to - 2] = '\0';
}

// int main(int c, char **argv){
// 	char *lal = argv[1];
// 	printf("%s\n", lal);
// 	ft_formatSpaces(lal);
// 	printf("%s\n", lal);
// }
