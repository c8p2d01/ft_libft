/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:41:07 by cdahlhof          #+#    #+#             */
/*   Updated: 2024/03/27 08:43:01 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "../../inc/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int		ft_get_next_line(int fd, char **line);

/*Utilities*/
char	*ft_isnewchar(char *buff);
#endif