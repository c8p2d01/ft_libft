/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_rand.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 15:28:48 by cdahlhof          #+#    #+#             */
/*   Updated: 2021/08/30 23:26:12 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	a fuction that gets a maximum and an amount as input
//	and gives amount many random, non duplicate numbers as output
//	invalid input is not yet handled

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int		ft_atoi(const char *str);
void	ft_putstr_fd(char *s);
char	*ft_itoa(int n);
char	*ft_calloc(size_t nmemb, size_t n);
int	dupes(char **nums);
int	ft_log(size_t b, int a);

int main(int argc, char **argv)
{
	int		i;
	char	**nums;

	i = 0;
	nums = (char **)ft_calloc(ft_atoi(argv[2]) + 1, sizeof(char *));
	if (argc != 3)
		return (0);
	while (i < ft_atoi(argv[2]))
	{
		nums[i] = ft_itoa(rand() % ft_atoi(argv[1]));
		if (dupes(nums) != 0)
			continue ;
		ft_putstr_fd(nums[i]);
		write(1, " ", 1);
		i++;
	}
	free(nums);
}

int	dupes(char **nums)
{
	int	i;
	int	s;
	int	l;

	l = 0;
	while (nums[l])
		l++;
	i = 0;
	while (l > i + 1)
	{
		s = i + 1;
		while(s < l && (ft_atoi(nums[i]) != ft_atoi(nums[s])))
			s++;
		if (s != l)
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	result[2];

	i = 0;
	result[0] = 0;
	result[1] = 1;
	while (str[i] && ((9 <= str[i] && str[i] <= 13) || str[i] == 32) != 0)
		i++;
	if (str[i] == '-')
		result[1] = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && '0' <= str[i] && str[i] <= '9')
	{
		result[0] = (result[0] * 10) + (str[i] - '0');
		i++;
	}
	return (result[0] * result[1]);
}

void	ft_putstr_fd(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write (1, &s[i], 1);
		i++;
	}
}

char	*ft_calloc(size_t nmemb, size_t n)
{
	char	*dest;
	size_t	i;

	dest = malloc(nmemb * n);
	if (!dest)
		return (0);
	i = 0;
	while (i < n * nmemb)
	{
		((char *)dest)[i] = '\0';
		i++;
	}
	return (dest);
}

int	ft_log(size_t b, int a)
{
	int	exp;

	exp = 1;
	while (b / a)
	{
		exp++;
		b /= a;
	}
	return (exp);
}

void	pitoa (long m, int p, int l, char *res)
{
	int	i;
	int	d;

	i = 0;
	d = 1;
	while (i < l - 1)
	{
		d *= 10;
		i++;
	}
	i = 0;
	while (i < l)
	{
		res[i + p] = (m / d) + 48;
		m %= d;
		d /= 10;
		i++;
	}
	res[i + p] = '\0';
}

char	*ft_itoa(int n)
{
	long	m;
	int		p;
	int		l;
	char	*res;

	m = (long)n;
	p = 0;
	if (m < 0)
		p = 1;
	if (p == 1)
		m *= -1;
	l = ft_log(m, 10);
	res = ft_calloc(l + p + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	if (p == 1)
		res[0] = '-';
	pitoa(m, p, l, res);
	return (res);
}