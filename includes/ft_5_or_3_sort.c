/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_5_or_3_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smadie <smadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 21:22:06 by smadie            #+#    #+#             */
/*   Updated: 2022/03/10 21:23:33 by smadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	if (stacks-> count_a == 1)
		exit(1);
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

void ft_5_elementsort(t_stacks *stacks)
{
	while (stacks->count_b < 2)
	{
		if (stacks->a->number == stacks->min || stacks->a->number == stacks->max)
			ft_pb(stacks,1);
		else
			ft_ra(&stacks->a,1);
	}
	ft_3_elementsort(stacks);
	ft_pa(stacks, 1);
	ft_pa(stacks, 1);
	if (stacks->a->number == stacks->max)
	{
		ft_ra(&stacks->a, 1);
	}
	else
	{
		ft_sa(stacks->a, 1);
		ft_ra(&stacks->a, 1);
	}
}
