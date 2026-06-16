/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:41:07 by cdahlhof          #+#    #+#             */
/*   Updated: 2025/10/10 19:07:05 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEM_H
# define FT_MEM_H

# include "../../inc/libft.h"

typedef struct s_list	t_list;
typedef struct	s_mem
{
	t_list	*mem;
	size_t	size;
	size_t	n_hold;
}	t_mem;

void	*ft_malloc(size_t size);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_realloc(void *old, size_t old_len, size_t add_len);
void	*ft_recycalloc(size_t size);

t_list	**memory(void);
t_list	*ft_memnew(void *content);
void	*ft_malloc(size_t size);
void	ft_free(void *del_block);
void	ft_clean_allocs(void);

t_mem	*get_pool(size_t size);
t_mem	*new_pool(size_t size);
void	ft_store_mem(void *del, size_t size);
void	ft_set_pool_size(size_t size, size_t n_hold);

#endif