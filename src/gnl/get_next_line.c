/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:41:04 by cdahlhof          #+#    #+#             */
/*   Updated: 2024/03/27 10:55:14 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_next_line(int fd)
{
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];
	int			reed;
	char		*leftover;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
		return (NULL);
	line = ft_strdup(buffer);
	ft_bzero(buffer, ft_strlen(line));
	reed = BUFFER_SIZE;
	while (!ft_strchr(line, '\n'))
	{
		line = ft_realloc(line, ft_strlen(line), BUFFER_SIZE + 1);
		reed = read(fd, line + ft_strlen(line), BUFFER_SIZE);
		if (reed <= 0)
		{
			free(line);
			return (NULL);
		}
	}
	leftover = ft_strchr(line, '\n') + 1;
	ft_memmove(buffer, leftover, ft_strlen(leftover));
	ft_bzero(leftover, ft_strlen(leftover));
	return (line);
}
