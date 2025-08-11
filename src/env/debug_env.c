/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 23:34:30 by cdahlhof          #+#    #+#             */
/*   Updated: 2025/08/10 03:23:06 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	print_env(void)
{
	t_list	*env;

	env = *persist_env();
	while (env)
	{
		ft_printf("stored env\t%s=%s\n", ((t_env_line *)env->content)->key, \
								((t_env_line *)env->content)->value);
		env = env->next;
	}
}
