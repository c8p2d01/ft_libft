/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:43:47 by cdahlhof          #+#    #+#             */
/*   Updated: 2025/01/12 13:44:50 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <stdarg.h>
# include <stdbool.h>
# include "../src/gnl/get_next_line.h"
# include "../src/lst/ft_list.h"
# include "../src/graph/ft_graph.h"
# include "../src/vector/ft_vector.h"

/*
	Memory mainpulation
*/

void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_realloc(void *old, size_t old_len, size_t add_len);
int			free_2dstr(char **s);
void		unreach(void *freeMe);
void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memccpy(void *dest, const void *src, int c, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		ft_char_rep(char *str, char target, char replacement);

t_list		**memory(void);
void		*ft_malloc(size_t size);
void		ft_free(void *del_block);
void		ft_clean_allocs(void);

/*
	Checks
*/

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_isnumeric(char *num);
int			ft_isdouble(char *num);
int			ft_2d_array_size(void **arr);

/*
	Conversion
*/

double		ft_atof(char *str);
int			ft_atoi(const char *nptr);
int			ft_atoi_base(const char *numberStr, const char *base);
char		*ft_itoa(int n);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		**ft_split(char const *s, char c);
char		**ft_set_split(char const *s, char *set);
void		i_limit(int *num, int low, int high);
void		f_limit(float *num, float low, float high);
void		lf_limit(double *num, double low, double high);

/*
	String mainpulation
 */

size_t		ft_strlen(const char *str);
size_t		ft_array_size(void **array);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_str_not_trim(char const *s1, char const *set);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_formatSpaces(char *s);
void		str_sed(char **base, char *ind, char *add);

/*
	Printing
*/

int			ft_printf(const char *str, ...);
int			ft_printf_fd(int fd, const char *str, ...);
void		printfile(int fd);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
int			ft_putnbr_base_fd(unsigned int num, char *base, int fd);

/*
	Color
*/

typedef struct s_color
{
	u_int8_t	r;
	u_int8_t	g;
	u_int8_t	b;
}	t_color;

t_color		new_color(int r, int g, int b);
int			create_rgb(int r, int g, int b);
int			print_color_from_hex(char *color);
long		create_gradient_color(float fraction, t_color a, t_color b);
long		create_multi_gradient(float fraction, int nColor, ...);

/*
	List
*/

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstfirst(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
