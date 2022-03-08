/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smadie <smadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:01:13 by smadie            #+#    #+#             */
/*   Updated: 2022/03/08 20:57:18 by smadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_max(t_stack *s)
{
	int max;

	max = s->number;
	while (s)
	{
		if (s->number > max)
			max = s->number;
		s = s->next;
	}
	return (max);
}

void ft_3_elementsort(t_stacks *stacks)
{
	int max;

	max = ft_max(stacks->a);
	if (stacks->count_a == 2)
	{
		if (stacks->a->number > stacks->a->next->number)
			ft_sa(stacks->a, 1);
		return ;
	}
	else if (stacks->count_a == 3)
	{
		if (stacks->a->number == max)
			ft_ra(&stacks->a, 1);
		if (stacks->a->next->number == max)
			ft_rra(&stacks->a, 1);
		if (stacks->a->number > stacks->a->next->number)
			ft_sa(stacks->a, 1);
	}
}

void ft_sort(t_stacks *stacks)
{
	if (stacks->count_a <= 3)
		ft_3_elementsort(stacks);
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
	ft_duplicate(new, stacks);
	ft_create_stacks(new, stacks);
	ft_sort(stacks);
	return (0);
}


