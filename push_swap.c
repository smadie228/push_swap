/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smadie <smadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:01:13 by smadie            #+#    #+#             */
/*   Updated: 2022/03/10 22:49:56 by smadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sort(t_stacks *stacks)
{
	if (stacks->count_a <= 3)
		ft_3_elementsort(stacks);
	else if (stacks->count_a <= 5)
		ft_5_elementsort(stacks);
	else
		ft_max_sort(stacks);
}


int main(int argc, char **argv)
{
	t_array *new;
	t_stacks *stacks;

	if (argc < 2)
		exit (1);
	if (!(new = (t_array *)malloc(sizeof(t_array))))
		exit (1);
	if (!(stacks = (t_stacks *)malloc(sizeof(t_stacks))))
		exit (1);
	ft_null_stack(stacks, new);
	create_array(argc, argv, new);
	ft_duplicate(new, stacks);
	ft_create_stacks(new, stacks);
	ft_sort(stacks);
	ft_free_stacks(stacks);
	free(new);
	free(stacks);
	return (0);
}


