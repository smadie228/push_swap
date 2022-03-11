/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smadie <smadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:33:54 by smadie            #+#    #+#             */
/*   Updated: 2022/03/11 20:38:28 by smadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

char	**ft_split(char const *s, char c, int *argc)
{
	char	**res;
	int		i;
	int		j;

	i = 0;
	j = 1;
	*argc = count_words(s, c) + 1;
	res = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!res)
		return (NULL);
	res[0] = ft_strdup("crutch");
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
	return (res);
}
