/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smadie <smadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:07:33 by smadie            #+#    #+#             */
/*   Updated: 2022/03/08 19:52:23 by smadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_ra(t_stack **a, int i)
{
	t_stack *original;
	t_stack *rotate_list;
	t_stack *second_list;

	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	rotate_list = *a;
	original = (*a)->next;
	second_list = *a;
	while (second_list->next !=NULL)
		second_list = second_list->next;
	rotate_list->next = NULL;
	second_list->next = rotate_list;
	*a = original;
	if (i == 1)
		write(1, "ra\n", 3);
}

void ft_rb(t_stack **b, int i)
{
	t_stack *original;
	t_stack *rotate_list;
	t_stack *second_list;

	if((*b) == NULL || (*b)->next == NULL)
		return ;
	rotate_list = *b;
	original = (*b)->next;
	second_list = *b;
	while (second_list->next != NULL)
		second_list = second_list->next;
	rotate_list->next = NULL;
	second_list->next = rotate_list;
	*b = original;
	if (i == 1)
		write(1, "rb\n", 3);
}

void ft_rr(t_stacks *s, int i)
{
	ft_ra(&s->a, 0);
	ft_rb(&s->b, 0);
		if(i == 1)
			write(1, "rr\n", 3);
}

void ft_rra(t_stack **a, int i)
{
	t_stack *original;
	t_stack *rotate_list;
	t_stack *second_list;

	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	original = *a;
	second_list = *a;
	while (second_list->next->next != NULL)
		second_list = second_list->next;
	rotate_list = second_list->next;
	second_list->next = NULL;
	rotate_list->next = original;
	*a = rotate_list;
	if (i == 1)
		write(1, "rra\n", 4);
}

void ft_rrb(t_stack **b, int i)
{
	t_stack *original;
	t_stack *rotate_list;
	t_stack *second_list;

	if ((*b) == NULL || (*b)->next == NULL)
		return ;
	original = *b;
	second_list = *b;
	while (second_list->next->next != NULL)
		second_list = second_list->next;
	rotate_list = second_list->next;
	second_list->next = NULL;
	rotate_list->next = original;
	*b = rotate_list;
	if (i == 1)
		write(1, "rra\n", 4);
}
