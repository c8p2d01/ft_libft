#include "./ft_print.h"

/**
 * @brief execution head for any printf parsing
 */
int	sprint(va_list a)
{
	t_p_vars	*p_vars;
	int			i;

	p_vars = *query();
	i = 0;
	while (p_vars->format[i])
	{
		p_vars = *query();
		if (p_vars->format[i] != '%')
		{
			if (ft_printchar(p_vars->format[i]) != 1)
				return (1);
		}
		else
		{
			p_vars->i = i + 1;
			if (trigger_insert(a))
				return (1);
			p_vars = *query();
			i += p_vars->skipped;
		}
		i++;
	}
	return (i);
}

/**
 * @brief the normal printf to STDOUT
 */
int	ft_printf(const char *format, ...)
{
	t_p_vars	*p_vars;
	va_list		a;
	int			process_return;
	int			written_length;

	if (ft_init(format))
		return (0);
	va_start(a, format);
	p_vars = *query();
	process_return = sprint(a);
	written_length = p_vars->written;
	if (process_return)
		va_end(a);
	return (ft_close(written_length));
}

/**
 * @brief printf bit args are already a va_list
 */
int	ft_vprintf(const char *format, va_list a)
{
	t_p_vars	*p_vars;
	int			process_return;
	int			written_length;

	if (ft_init(format))
		return (0);
	p_vars = *query();
	process_return = sprint(a);
	written_length = p_vars->written;
	if (process_return)
		va_end(a);
	return (ft_close(written_length));
}

/**
 * @brief printf but output to specified fd
 */
int	ft_printf_fd(int fd, const char *format, ...)
{
	t_p_vars	*p_vars;
	va_list		a;
	int			process_return;
	int			written_length;

	if (ft_init(format))
		return (0);
	p_vars = *query();
	p_vars->fd = fd;
	va_start(a, format);
	process_return = sprint(a);
	written_length = p_vars->written;
	if (process_return)
		va_end(a);
	return (ft_close(written_length));
}

/**
 * @brief printf but output to specified FILE pointer and args are already a va_list
 */
int	ft_vfprintf(FILE *f, const char *format, va_list a)
{
	t_p_vars	*p_vars;
	int			process_return;
	int			written_length;

	if (ft_init(format))
		return (0);
	p_vars = *query();
	p_vars->debug = true;
	p_vars->f = f;
	process_return = sprint(a);
	written_length = p_vars->written;
	if (process_return)
		va_end(a);
	return (ft_close(written_length));
}

/**
 * @brief printf but output to a char* allocated by this function
 */
char *ft_asprintf(const char *format, ...)
{
	t_p_vars	*p_vars;
	va_list		a;
	int			process_return;
	int			written_length;
	char		*result;

	if (ft_init(format))
		return (0);
	p_vars = *query();
	p_vars->as = ft_calloc(1, 1);
	va_start(a, format);
	process_return = sprint(a);
	written_length = p_vars->written;
	if (process_return)
		va_end(a);
	result = ft_malloc(p_vars->as_written + 1);
	if (!result)
		return (ft_close(written_length), NULL);
	ft_strlcpy(result, p_vars->as, p_vars->as_written + 1);
	return (ft_close(written_length), result);
}

#ifdef TEST

int main(int argc, char **argv)
{
	(void)argc;
	printf("testing file %s\n", argv[0]);

	{
		printf("testing ft_printf\n");
		{
			int res;
			printf("mine\t");
			res = ft_printf("Hello World");
			printf("\noutput: %i\n", res);
			printf("orig\t");
			res = printf("Hello World");
			printf("\noutput: %i\n", res);
		}
	}
}

#endif