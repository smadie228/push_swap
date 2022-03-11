/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smadie <smadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:48:34 by smadie            #+#    #+#             */
/*   Updated: 2022/03/11 07:25:06 by smadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_countword(char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != ' ' && *s != '\t')
		{
			count++;
			while ((*s != ' ' && *s != '\t') && *s != '\0')
				s++;
		}
		else
			s++;
	}
	return (count);
}

void	ft_stacking(t_array *new, int *buff, int count)
{
	int	i;

	i = -1;
	while (count > ++i)
		new->a[new->count_element + i] = buff[i];
	new->count_element += count;
	free(buff);
}

void	create_array(int argc, char **argv, t_array *new)
{
	char	**mass;
	int		p;
	int		i;
	int		count_element;
	int		*buff;

	i = 1;
	while (i < argc)
	{
		p = -1;
		count_element = ft_countword(argv[i]);
		mass = ft_split(argv[i], ' ');
		buff = (int *)malloc(sizeof(int) * (count_element));
		if (!(buff))
			exit(1);
		while (count_element > ++p)
		{
			buff[p] = ft_atoi(mass[p]);
			free(mass[p]);
		}
		free(mass);
		ft_stacking(new, buff, count_element);
		i++;
	}
}
