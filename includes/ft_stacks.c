/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smadie <smadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:10:58 by smadie            #+#    #+#             */
/*   Updated: 2022/03/08 20:56:27 by smadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
		if (i == (count  - 1))
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