/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:41:12 by cdahlhof          #+#    #+#             */
/*   Updated: 2024/03/10 20:59:42 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	skipWhitespace(const char *numberStr, const char *base)
{
	int		toSkip			= 0;
	char	*whitespaces	= "\t\n\v\f\r ";

	for (int i = 0; numberStr[i]; i++)
	{
		if (ft_strchr(whitespaces, numberStr[i]) && !ft_strchr(base, numberStr[i]))
		{
			toSkip++;
			continue;
		}
		break;
	}
	return (toSkip);
}

int	isNegative(const char *numberStr, int *i, const char *base)
{
	char	sign = numberStr[(*i)];
	int		result = 1;

	if (sign == '-' && !ft_strchr(base, '-'))
	{
		result = -1;
		i[0]++;
	}
	else if (sign == '+' && !ft_strchr(base, '+'))
	{
		(*i)++;
	}
	return (result);
}

int	charInBase(char i, const char *base)
{
	if (i)
		return (base - ft_strchr(base, i));
	return (i);
}

int	valueInBase(char i, const char *base)
{
	char	*charInBase = ft_strchr(base, i);

	if (!charInBase)
		return (0);
	return (charInBase - base);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == 32)
		i++;
	if (nptr[i] == 43 || nptr[i] == 45)
	{
		if (nptr[i] == 45)
			sign *= -1;
		i++;
	}
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		num = num * 10 + nptr[i] - '0';
		i++;
	}
	return (num * sign);
}

int	ft_atoi_base(const char *numberStr, const char *base)
{
	int	i;
	int	sign;
	int	result;

	result = 0;
	i = skipWhitespace(numberStr, base);
	sign = isNegative(numberStr, &i, base);
	while (charInBase(numberStr[i], base))
	{
		result *= ft_strlen(base);
		result += valueInBase(numberStr[i], base);
		i++;
	}
	return (result * sign);
}
