#include "../../inc/libft.h"

void	ft_putfloat_fd(int fd, float num, int decimals)
{
	long long	int_part;
	long long	temp;
	long long	divisor;
	char		c;

	if (num < 0)
	{
		write(fd, "-", 1);
		num = -num;
	}
	int_part = (long long)num;
	divisor = 1;
	while ((int_part / divisor) >= 10)
		divisor *= 10;
	while (divisor > 0)
	{
		c = (int_part / divisor) % 10 + '0';
		write(fd, &c, 1);
		divisor /= 10;
	}
	if (decimals > 0)
	{
		write(fd, ".", 1);
		num -= (long long)num;
		while (decimals-- > 0)
		{
			num *= 10;
			c = (int)num + '0';
			write(fd, &c, 1);
			num -= (int)num;
		}
	}
}
