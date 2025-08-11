/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 23:15:51 by cdahlhof          #+#    #+#             */
/*   Updated: 2025/08/11 04:19:00 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

t_list	**persist_env(void)
{
	static t_list	*mem;

	return (&mem);
}

static t_list	*transfer_line(char *env_line)
{
	t_list		*new;
	t_env_line	*content;
	char		*eq;

	content = ft_calloc(sizeof(t_env_line), 1);
	new = ft_lstnew((void *)content);
	if (content && new && env_line)
	{
		eq = ft_strchr(env_line, '=');
		if (eq)
		{
			content->key = ft_substr(env_line, 0, eq - env_line);
			content->value = ft_substr(eq + 1, 0, ft_strlen(eq + 1));
		}
		else
			content->key = ft_strdup(env_line);
	}
	return (new);
}

void	setup_env(char **p_env)
{
	t_list	*env;
	int		i;

	env = *persist_env();
	if (!env)
	{
		i = 0;
		while (p_env && p_env[i])
		{
			ft_lstadd_back(persist_env(), transfer_line(p_env[i]));
			i++;
		}
	}
}

void	del_env_line(void *p_content)
{
	t_env_line	*content;

	content = (t_env_line *)p_content;
	if (!content)
		return ;
	if (content->key)
	{
		ft_free(content->key);
		content->key = NULL;
	}
	if (content->value)
	{
		ft_free(content->value);
		content->value = NULL;
	}
	ft_free (content);
}

void	clear_env(void)
{
	ft_lstclear(persist_env(), del_env_line);
}
