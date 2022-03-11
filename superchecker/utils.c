/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smadie <smadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:33:54 by smadie            #+#    #+#             */
/*   Updated: 2022/03/11 20:39:10 by smadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_atoi(const char *s)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (s[i] == '\t' || s[i] == '\n' || s[i] == '\v'
		|| s[i] == '\f' || s[i] == '\r' || s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
		if (s[i++] == '-')
			sign = -sign;
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + s[i++] - '0';
		if (res < 0)
		{
			if (sign > 0)
				return (-1);
			return (0);
		}
	}
	return (res * sign);
}

static int	count_words(const char *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (str[0] != c)
		count++;
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c && str[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

static int	sub_len(const char *start, char c)
{
	int	i;

	i = 0;
	while (start[i] != c && start[i])
		i++;
	return (i);
}

static char	**free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char	**ft_lib_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!res)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			res[j] = ft_substr(&s[i], 0, sub_len(&s[i], c));
			if (NULL == res[j++])
				return (free_arr(res));
			i += sub_len(&s[i], c);
		}
		else
			i++;
	}
	res[j] = NULL;
	return (res);
}
