/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:41:04 by cdahlhof          #+#    #+#             */
/*   Updated: 2024/04/04 17:53:05 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
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
	while (!ft_strchr(line, '\n') && reed > 0)
	{
		line = ft_realloc(line, ft_strlen(line), BUFFER_SIZE + 1);
		reed = read(fd, line + ft_strlen(line), BUFFER_SIZE);
		if (reed <= 0)
		{
			if (ft_strlen(line))
				return (line);
			return (free(line), NULL);
		}
	}
	leftover = ft_strchr(line, '\n') + 1;
	ft_memcpy(buffer, leftover, ft_strlen(leftover));
	ft_bzero(leftover, ft_strlen(leftover));
	return (line);
}
