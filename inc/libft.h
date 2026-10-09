/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:43:47 by cdahlhof          #+#    #+#             */
/*   Updated: 2026/03/30 13:16:32 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <math.h>
# include <sys/types.h>
# include <stdarg.h>
# include <stdbool.h>
# include "../src/memory/ft_memory.h"
# include "../src/list/ft_list.h"
# include "../src/reading/ft_read.h"
# include "../src/vector/ft_vector.h"
# include "../src/print/ft_print.h"
# include "../src/color/ft_color.h"

//# define TEST 1

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
long		ft_atol(const char *nptr);
char		*ft_itoa(int n);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		**ft_split(char const *s, char c);
char		**ft_set_split(char const *s, char *set);
void		i_limit(int *num, int low, int high);
void		f_limit(float *num, float low, float high);
void		lf_limit(double *num, double low, double high);
int			ft_log(unsigned long num, int base);
int			ft_count_digit(unsigned long num, int base);

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
int			ft_strlcmp(const char *s1, const char *s2, size_t limit);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_str_not_trim(char const *s1, char const *set);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_formatSpaces(char *s);
void		str_sed(char **base, char *ind, char *add);
char		*ft_strmerge(char *s1, char *s2);
char		*ft_strsmerge(size_t n, ...);

/*
	Environment
*/

typedef struct s_env_line{
	char	*key;
	char	*value;
}	t_env_line;

t_list		**persist_env(void);
void		setup_env(char **p_env);
void		print_env(void);
void		del_env_line(void *p_content);
void		clear_env(void);
char		*get_value(char *key);

#endif
