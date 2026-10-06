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

/*
	Memory mainpulation
*/

int		free_2dstr(char **s);
void	unreach(void *freeMe);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_char_rep(char *str, char target, char replacement);

/*
	Persistent Memory Anchors
*/

t_list	**memory(void);
t_list	**storage_pools(void);
t_list	**opened_files();

/*
	Persistent Memory
*/

void	*ft_malloc(size_t size);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_realloc(void *old, size_t old_len, size_t add_len);
void	*ft_recycalloc(size_t size);

t_list	*ft_memnew(void *content);
t_mem	*get_pool(size_t size);
t_mem	*new_pool(size_t size);
void	ft_store_mem(void *del, size_t size);
void	ft_set_pool_size(size_t size, size_t n_hold);

int		allocation_error(void);
void	ft_free(void *del_block);
void	ft_clean_fds(void);
void	ft_clean_allocs(void);

#endif