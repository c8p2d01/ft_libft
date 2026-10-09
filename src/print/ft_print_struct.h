#ifndef FT_PRINT_STRUCT_H
# define FT_PRINT_STRUCT_H

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
	char	*as;
	int		as_remaining;
	int		as_written;
}	t_p_vars;

#endif