/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 20:03:05 by cdahlhof          #+#    #+#             */
/*   Updated: 2025/08/11 04:24:57 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdbool.h>

# include <stdio.h>
# include <limits.h>
# include <string.h>

# include "../../../inc/libft.h"

typedef struct s_p_vars
{
	char	*format;
	char	*insert;
	int		i;
	int		skipped;
	int		written;
	int		added;
	int		add;
	int		len;

	bool	do_sign;
	bool	do_width;
	bool	do_precision;
	bool	sign_positive;
	bool	is_negative;
	bool	leftbound;
	char	padd_char;
	bool	pointer_prefix;
	int		width;
	int		precision;
	int		pad;
	int		p_i;
	char	insert_identifier;

	int		value_length;
	char	*value_base;
	char	*temp;
	char	*string;
	char	c;

	bool	debug;
	FILE	*f;
	int		fd;
}	t_p_vars;

t_p_vars	**query(void);

int			reset_flags_extension(void);
int			reset_flags(void);
int			ft_init(const char *format);
int			ft_close(int return_value);

int			ft_printchar(char c);
int			repeat_char(char c, size_t n);
int			print_base(char *base, unsigned long nbr);
void		print_base_to_mem(char *dest, char *base, unsigned long nbr);

int			string_padding(void);
int			char_padding_extension(void);
int			char_padding(void);

void		set_pad(unsigned long num);
void		handle_precision(void);
void		handle_sign(void);
void		handle_pointy(void);
void		handle_leftsbound(void);
int			handle_padding(unsigned long num);

int			delegate_handlers(va_list a);
int			handle_d_i(va_list a);
int			handle_u(va_list a);
int			handle_p(va_list a);
int			handle_x(va_list a);
int			handle_big_x(va_list a);
int			handle_c(va_list a);
int			handle_percent(void);
int			handle_s(va_list a);

void		read_numbers(void);
void		read_flags(void);
int			trigger_insert(va_list a);
int			sprint(va_list a);

int			ft_printf(const char *format, ...);
int			ft_vfprintf(FILE *f, const char *format, va_list a);
void		compare(char *fmt, ...);

#endif