/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smadie228 <smadie228@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:59:52 by smadie            #+#    #+#             */
/*   Updated: 2022/03/11 17:46:00 by smadie228        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	else
		return (0);
}

long long int	ft_atoi(const char *str)
{
	long long int	g;
	int	n;

	g = 0;
	n = 1;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			n = n * (-1);
		str++;
	}
	while (ft_isdigit(*str))
	{
		g = g * 10;
		g = g + (*str - '0');
		str++;
	}
	return (n * g);
}
