/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smadie <smadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:42:12 by smadie            #+#    #+#             */
/*   Updated: 2022/03/11 03:11:47 by smadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_sa(t_stack *a, int i)
{
	int	z;

	if (a == NULL || a->next == NULL)
		return ;
	z = a ->number;
	a->number = a->next->number;
	a->next->number = z;
	if ( i == 1)
		write(1, "sa\n", 3);
}

void ft_sb(t_stack *b, int i)
{
	int z;

	if (b == NULL || b->next == NULL)
		return ;
	z = b ->number;
	b->number = b->next->number;
	b->next->number = z;
	if ( i == 1)
		write(1, "sb\n", 3);
}

void ft_ss(t_stacks *s, int i)
{
	ft_sa(s->a, 0);
	ft_sb(s->b, 0);
	if ( i == 1)
		write(1, "ss\n", 3);
}

void ft_pa(t_stacks *s, int i)
{
	t_stack *z;

	if (s->b == NULL)
		return ;
	s->count_a += 1;
	s->count_b -= 1;
	z = s->b;
	s->b = s->b->next;
	z->next = s->a;
	s->a = z;
	if (i == 1)
		write(1, "pa\n", 3);
}

void ft_pb(t_stacks *s, int i)
{
	t_stack *z;

	if(s->a == NULL)
		return ;
	s->count_a -=1;
	s->count_b +=1;
	z = s->a;
	s->a = s->a->next;
	z->next = s->b;
	s->b = z;
	if ( i == 1)
		write(1, "pb\n", 3);
}
