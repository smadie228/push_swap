/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smadie <smadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:07:33 by smadie            #+#    #+#             */
/*   Updated: 2022/03/07 15:13:42 by smadie           ###   ########.fr       */
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
		write(1, "ra/n", 3);
}
