/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlhof <cdahlhof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:41:12 by cdahlhof          #+#    #+#             */
/*   Updated: 2024/04/04 17:52:33 by cdahlhof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static int	skip_whitespace(const char *s, const char *base)
{
	int		to_skip;
	int		i;
	char	*whitespaces;

	to_skip = 0;
	whitespaces = "\t\n\v\f\r ";
	i = 0;
	while (s && s[i])
	{
		if (ft_strchr(whitespaces, s[i]) && !ft_strchr(base, s[i]))
		{
			to_skip++;
			i++;
			continue ;
		}
		break ;
	}
	return (to_skip);
}

static int	is_negative(const char *numberStr, int *i, const char *base)
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

static int	char_in_base(char i, const char *base)
{
	if (i)
		return (base - ft_strchr(base, i));
	return (i);
}

static int	value_in_base(char i, const char *base)
{
	char	*char_in_b;

	char_in_b = ft_strchr(base, i);
	if (!char_in_b)
		return (0);
	return (char_in_b - base);
}

int	ft_atoi_base(const char *numberStr, const char *base)
{
	int	i;
	int	sign;
	int	result;

	result = 0;
	i = skip_whitespace(numberStr, base);
	sign = is_negative(numberStr, &i, base);
	while (char_in_base(numberStr[i], base))
	{
		result *= ft_strlen(base);
		result += value_in_base(numberStr[i], base);
		i++;
	}
	return (result * sign);
}
