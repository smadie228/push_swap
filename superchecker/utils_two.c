/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smadie <smadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:33:54 by smadie            #+#    #+#             */
/*   Updated: 2022/03/11 20:39:06 by smadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	**arg_parse(char *arg, int *argc)
{
	char	**res;

	if (!arg)
		return (NULL);
	res = ft_split(arg, ' ', argc);
	if (!res)
		return (NULL);
	return (res);
}

void	free_array(char **arr, int argc)
{
	int	i;

	if (arr)
	{
		i = 0;
		while (i < argc)
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
}

void	free_array_lib(char **arr)
{
	int	i;

	if (arr)
	{
		i = 0;
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
}

int	check_is_sort(t_list *a)
{
	while (a->next)
	{
		if (a->i > a->next->i)
			return (1);
		a = a->next;
	}
	return (0);
}

void	final_check(t_list **a, t_list **b)
{
	if (a && b)
	{
		if (!check_is_sort(*a))
		{
			if (list_size(*b) == 0)
			{
				write(1, "OK\n", 3);
				exit(EXIT_SUCCESS);
			}
		}
	}
	write(1, "KO\n", 3);
	exit(EXIT_FAILURE);
}
