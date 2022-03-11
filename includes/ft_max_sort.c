/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smadie <smadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 22:02:04 by smadie            #+#    #+#             */
/*   Updated: 2022/03/11 07:26:53 by smadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_max_sort(t_stacks *stacks)
{
	while (stacks->count_a > 2)
	{
		if (stacks->a->number != stacks->min
			&& stacks->a->number != stacks->max)
		{
			ft_pb(stacks, 1);
			if (stacks->b->number > stacks->med)
				ft_rb(&stacks->b, 1);
		}
		else
			ft_ra(&stacks->a, 1);
	}
	if (stacks->a->number < stacks->a->next->number)
		ft_sa(stacks->a, 1);
	ft_pa(stacks, 1);
	ft_begin_sort(stacks);
}

void	ft_steps_pointed(t_stack *b, int count)
{
	t_stack	*buff;
	int		i;
	int		point;

	i = -1;
	point = count / 2;
	buff = b;
	while (++i <= point)
	{
		buff->step = i;
		buff->rotate = 1;
		buff = buff->next;
	}
	if (count % 2 == 0)
		i--;
	while (--i > 0)
	{
		buff->step = i;
		buff->rotate = -1;
		buff = buff->next;
	}
}

void	ft_min_step(t_stacks *stacks, t_steps *steps)
{
	int		min;
	t_stack	*first_a;
	t_stack	*first_b;

	min = -1;
	first_a = stacks->a;
	first_b = stacks->b;
	while (stacks->b)
	{
		min = ft_finding_place(stacks, stacks->b, steps, min);
		stacks->a = first_a;
		stacks->b = stacks->b->next;
	}
	stacks->b = first_b;
}

void	ft_instruction_step(t_stacks *stacks, t_steps *steps)
{
	while (steps->count_a > 0)
	{
		if (steps->dest_a == 1)
			ft_ra(&stacks->a, 1);
		else
			ft_rra(&stacks->a, 1);
		steps->count_a--;
	}
	while (steps->count_b > 0)
	{
		if (steps->dest_b == 1)
			ft_rb(&stacks->b, 1);
		else
			ft_rrb(&stacks->b, 1);
		steps->count_b--;
	}
	ft_pa(stacks, 1);
}

void	ft_begin_sort(t_stacks *stacks)
{
	t_steps	*step;

	step = (t_steps *)malloc(sizeof(t_steps));
	if (!(step))
		exit (1);
	while (stacks->count_b != 0)
	{
		step->count_a = -1;
		step->count_b = -1;
		step->dest_a = 0;
		step->dest_b = 0;
		ft_steps_pointed(stacks->a, stacks->count_a);
		ft_steps_pointed(stacks->b, stacks->count_b);
		ft_min_step(stacks, step);
		ft_instruction_step(stacks, step);
	}
	if ((ft_count_to_min(stacks->a, stacks->min)) > stacks->count_a / 2)
	{
		while (stacks->a->number != stacks->min)
			ft_rra(&stacks->a, 1);
	}
	else
		while (stacks->a->number != stacks->min)
			ft_ra(&stacks->a, 1);
	free(step);
}
