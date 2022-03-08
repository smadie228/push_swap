/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quik_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smadie <smadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:17:40 by smadie            #+#    #+#             */
/*   Updated: 2022/03/08 20:25:05 by smadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_quick_sort(int *array, int firsr_element, int last_element)
{
	int z;

	if (firsr_element < last_element)
	{
		z = ft_part(array,firsr_element,last_element);
		ft_quick_sort(array,firsr_element, z - 1);
		ft_quick_sort(array, z + 1, last_element);
	}
}

int ft_part(int *array, int start, int end)
{
	int i;
	int j;
	int pivot;
	int temp;

	pivot = array[end];
	i = start - 1;
	j = start;
	while (j < end)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
		j++;
	}
	temp = array[i + 1];
	array[i + 1] = array[end];
	array[end] = temp;
	return (i + 1);
}
