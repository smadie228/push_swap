/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smadie <smadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 23:03:46 by smadie            #+#    #+#             */
/*   Updated: 2022/03/11 02:27:33 by smadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int ft_spaces(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == ' ' || str[i] == '\r' || str[i] == '\f')
			i++;
		else
			return (1);
	}
	return (0);
}

void ft_validation_number(char *str)
{
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
			return ;
		str++;
	}
	ft_error();
}

void ft_validation_str(char *str)
{
	size_t	i;
	int		nbr;
	int		sign;

	i = 0;
	nbr = 0;
	sign = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			nbr++;
		else if (str[i] == ' ' || str[i] == '\t')
		{
			if (sign != 0 && nbr == 0)
				ft_error();
			nbr = 0;
			sign = 0;
		}
		else if (((str[i] == '+' || str[i] == '-') &&
				(sign == 0 && nbr == 0)) && (str[i + 1] != '\0'))
			sign++;
		else
			ft_error();
		i++;
	}
}

int ft_validation(int argc, char **argv)
{
	int i;
	int validation;

	validation = 0;
	i = 1;
	while (i < argc)
	{
		if (ft_spaces(argv[i]))
		{
			ft_validation_number(argv[i]);
			ft_validation_str(argv[i]);
			validation = 1;
		}
		i++;
	}
	return (validation);
}
