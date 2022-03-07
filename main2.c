/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smadie <smadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:01:13 by smadie            #+#    #+#             */
/*   Updated: 2022/03/07 13:09:12 by smadie           ###   ########.fr       */
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

void	ft_stacking(t_array *new, int *buff, int count)
{
	new->a[new->count_element] = *buff;
	new->count_element++;
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
		mass = ft_split(argv[i], ' ');
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

/// Здесь перекидываем наш массив с использованеим Stack в А

t_stack *ft_create_stack(int *buff, int count)
{
	int i;
	t_stack	*list;
	t_stack *first_number;

	i = 0;
	if(!(list= (t_stack *)malloc(sizeof(t_stack))))
		exit(1);
	first_number = list;
	while (i < count)
	{
		if (i < count - 1)
		{
			if (!(list->next = (t_stack *)malloc(sizeof(t_stack))))
				exit(1);
		}
		list->number = buff[i];
		//printf("%d\n",list->number);
		if (i == (count  - i))
			list->next = NULL;
		else
			list = list ->next;
		i++;
	}
	return (first_number);
}

////==============Здесь инициализируем два листа со стеком А и B
void ft_create_stacks(t_array *new, t_stacks *stacks)
{
	stacks->a = ft_create_stack(new->a,new->count_element);
	stacks->b = NULL;
}


int main(int argc, char **argv)
{
	t_array *new;
	t_stacks *stacks;


	if (argc < 2)
		return (1);
	if (!(new = (t_array *)malloc(sizeof(t_array))))
		return (1);
	if (!(stacks = (t_stacks *)malloc(sizeof(t_stacks))))
		return (1);

	create_array(argc, argv, new);
	ft_create_stacks(new, stacks);
	int i = 0;
	while (10 > i)
	{
		printf("%d",stacks->a->number);
		i++;
	}

	return (0);
}


