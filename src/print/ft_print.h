#ifndef FT_PRINT_H
# define FT_PRINT_H

# include "../../inc/libft.h"

# include "ft_print_struct.h"

# ifndef ALLOCATION_SIZE
#  define ALLOCATION_SIZE 1024
# endif

/*
	Basics
*/

void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	print_base_to_mem(char *dest, char *base, unsigned long nbr);
int		print_base(char *base, unsigned long nbr);
int		ft_putnbr_base_fd(unsigned int num, char *base, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);

/*
	Printf
*/

t_p_vars	**query(void);

int		reset_flags_extension(void);
int		reset_flags(void);
int		ft_init(const char *format);
int		ft_close(int return_value);

int		ft_printchar(char c);
int		repeat_char(char c, size_t n);
int		print_base(char *base, unsigned long nbr);
void	print_base_to_mem(char *dest, char *base, unsigned long nbr);

int		string_padding(void);
int		char_padding_extension(void);
int		char_padding(void);

void	set_pad(unsigned long num);
void	handle_precision(void);
void	handle_sign(void);
void	handle_pointers(void);
void	handle_leftsbound(void);
int		handle_padding(unsigned long num);

int		delegate_handlers(va_list a);
int		handle_d_i(va_list a);
int		handle_u(va_list a);
int		handle_p(va_list a);
int		handle_x(va_list a);
int		handle_big_x(va_list a);
int		handle_c(va_list a);
int		handle_percent(void);
int		handle_s(va_list a);

void	read_numbers(void);
void	read_flags(void);
int		trigger_insert(va_list a);
int		sprint(va_list a);

int		ft_printf(const char *format, ...);
int		ft_vprintf(const char *format, va_list a);
int		ft_vfprintf(FILE *f, const char *format, va_list a);
char	*ft_asprintf(const char *format, ...);
void	compare(char *fmt, ...);

#endif