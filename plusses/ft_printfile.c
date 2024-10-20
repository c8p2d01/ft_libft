/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:00:57 by cdahlhof          #+#    #+#             */
/*   Updated: 2024/04/04 18:24:46 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	printfile(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		printf("%s\n", line);
		free (line);
		line = get_next_line(fd);
	}
}
