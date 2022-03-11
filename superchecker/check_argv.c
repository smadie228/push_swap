/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smadie <smadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:33:54 by smadie            #+#    #+#             */
/*   Updated: 2022/03/11 20:38:00 by smadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

static long	ft_atol(const char *s)
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
		res = res * 10 + s[i++] - '0';
	return (res * sign);
}

int	check_repeat(char **arr, int argc)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (!ft_strcmp(arr[i], arr[j]))
				count++;
			j++;
		}
		i++;
	}
	if (count > 0)
		return (1);
	return (0);
}

int	check_minmax(char **arr, int argc)
{
	int		i;
	long	l;

	i = 1;
	while (i < argc)
	{
		if (ft_strlen(arr[i]) == 0)
			return (1);
		if (ft_strlen(arr[i]) > 11)
			return (1);
		l = ft_atol(arr[i]);
		if (l > MY_INT_MAX || l < MY_INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	check_digit(char **arr, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][0] == '-' && arr[i][1] == '0')
				return (1);
			if (arr[i][0] == '+' && arr[i][1] == '0')
				return (1);
			if (arr[i][j] == '-' && j == 0)
				j++;
			else if (arr[i][j] == '+' && j == 0)
				j++;
			if (!ft_isdigit(arr[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
