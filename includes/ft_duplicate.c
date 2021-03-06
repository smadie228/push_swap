/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duplicate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smadie <smadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:37:07 by smadie            #+#    #+#             */
/*   Updated: 2022/03/11 07:26:10 by smadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*ft_intcopy(int *dst, int *src, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

void	ft_search_duplicate(int *duplicate, int count)
{
	int	i;

	i = 0;
	while (i != count)
	{
		if (duplicate[i] == duplicate[i + 1])
		{
			ft_error();
		}
		i++;
	}
}

void	ft_duplicate(t_array *new, t_stacks *stacks)
{
	int	*duplicate;

	duplicate = (int *)malloc(sizeof(int) * (new->count_element));
	if (!(duplicate))
		exit(1);
	duplicate = ft_intcopy(duplicate, new->a, new->count_element);
	ft_quick_sort(duplicate, 0, new->count_element - 1);
	ft_search_duplicate(duplicate, new->count_element - 1);
	stacks->count_a = new->count_element;
	stacks->count_b = 0;
	stacks->min = duplicate[0];
	stacks->med = duplicate[new->count_element / 2];
	stacks->max = duplicate[new->count_element - 1];
	free(duplicate);
}
