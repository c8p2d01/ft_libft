/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:41:12 by cdahlhof          #+#    #+#             */
/*   Updated: 2024/03/14 22:31:54 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	skipWhitespace(const char *s, const char *base)
{
	int		toSkip;
	int		i;
	char	*whitespaces;

	toSkip = 0;
	whitespaces = "\t\n\v\f\r ";
	i = 0;
	while (s && s[i])
	{
		if (ft_strchr(whitespaces, s[i]) && !ft_strchr(base, s[i]))
		{
			toSkip++;
			i++;
			continue ;
		}
		break ;
	}
	return (toSkip);
}

int	isNegative(const char *numberStr, int *i, const char *base)
{
	char	sign;
	int		result;

	result = 1;
	sign = numberStr[(*i)];
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
	char	*charInBase;

	charInBase = ft_strchr(base, i);
	if (!charInBase)
		return (0);
	return (charInBase - base);
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
