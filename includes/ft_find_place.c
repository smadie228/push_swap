/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_place.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smadie <smadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 21:53:56 by smadie            #+#    #+#             */
/*   Updated: 2022/03/10 21:59:54 by smadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_help_finding_place(t_stacks *s, t_stack *b, int *action, int *buff)
{
	while (s->a)
	{
		*buff = s->a->number;
		if (b->number > s->a->number)
		{
			*action += 1;
			if (b->number < s->a->next->number)
				break ;
			s->a = s->a->next;
		}
		else
			break ;
	}
	if (ft_smaller_element_detection(s->a, *buff, b->number) == 1)
	{
		while (s->a)
		{
			if (s->a->number < *buff && s->a->number > b->number)
				break ;
			*action += 1;
			s->a = s->a->next;
		}
	}
}

int		ft_finding_place(t_stacks *s, t_stack *b, t_steps *steps, int min)
{
	int action;
	int res;
	int buff;

	action = 0;
	buff = 0;
	ft_help_finding_place(s, b, &action, &buff);
	if (s->a->rotate == -1)
		action = s->count_a - action;
	if (min == -1 || (action + b->step) < min)
	{
		steps->dest_a = s->a->rotate;
		steps->dest_b = b->rotate;
		steps->count_a = action;
		steps->count_b = b->step;
		res = action + b->step;
	}
	else
		res = min;
	return (res);
}

int		ft_smaller_element_detection(t_stack *a, int buff, int src)
{
	t_stack	*save;
	int		ret;

	save = a;
	ret = 0;
	while (save && ret == 0)
	{
		if (save->number < buff && save->number > src)
			ret = 1;
		save = save->next;
	}
	return (ret);
}

int		ft_count_to_min(t_stack *a, int min)
{
	int i;

	i = 0;
	while (a)
	{
		if (a->number == min)
			break ;
		a = a->next;
		i++;
	}
	return (i);
}
