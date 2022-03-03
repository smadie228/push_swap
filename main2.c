/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smadie <smadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:01:13 by smadie            #+#    #+#             */
/*   Updated: 2022/03/03 23:33:53 by smadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_countword(char *s)
{
	int count;

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

void create_array(int argc, char **argv, t_array *new)
{
	int p;
	int i;
	int count_element;
	int		*buff; // созданеи буфера
	char	**mass;

	i = 1;

	while (i < argc)
	{
		p = -1;
		count_element = ft_countword(argv[i]);
		mass = ft_split(argv[i], '1');
		if (!(buff = (int *)malloc(sizeof(int) * (count_element))))
			exit(1);
		while (count_element > ++p)
		{
			buff[p] = ft_atoi(mass[p]);
		}
		ft_stacking(new, buff, count_element);
		i++;
	}
}

void	ft_stacking(t_array *new, int *buff, int count)
{
	int i;

	i = -1;
	while(count > ++i)
		new->a[new->count_element + i] = buff[i];
	new->count_element += count;
	printf("%d,"new->count_elememt);
}

int main(int argc, char **argv)
{
	t_array *new;
	if (!(new = (t_array *)malloc(sizeof(t_array))))
		exit(1);
	if (argc < 2)
		exit (1);

	create_array(argc, argv, new);

	return (0);
}
