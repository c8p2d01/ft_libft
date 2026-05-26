#include "../../inc/libft.h"

static double	ft_getfraction(char *str)
{
	double	fraction;
	double	divisor;

	fraction = 0.0;
	divisor = 1.0;
	while (*str >= '0' && *str <= '9')
	{
		fraction = fraction * 10.0 + (*str - '0');
		divisor *= 10.0;
		str++;
	}
	return (fraction / divisor);
}

double	ft_atof(char *str)
{
	double	integer_part;
	double	fraction_part;
	double	sign;

	integer_part = 0.0;
	fraction_part = 0.0;
	sign = 1.0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1.0;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		integer_part = integer_part * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
		fraction_part = ft_getfraction(str + 1);
	return (sign * (integer_part + fraction_part));
}
