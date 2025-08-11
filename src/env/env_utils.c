/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 23:53:31 by cdahlhof          #+#    #+#             */
/*   Updated: 2025/08/10 03:23:35 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*get_value(char *key)
{
	t_list		*env;
	t_env_line	*line;

	env = *persist_env();
	while (env)
	{
		line = (t_env_line *)env->content;
		if (ft_strncmp(key, line->key, ft_strlen(line->key)) == 0)
			return (line->value);
		env = env->next;
	}
	return (NULL);
}
