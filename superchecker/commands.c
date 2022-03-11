/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smadie <smadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:33:54 by smadie            #+#    #+#             */
/*   Updated: 2022/03/11 20:38:19 by smadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_exe(t_list **list, int flag)
{
	int	i;
	int	tmp;

	if (*list)
	{
		i = list_size(*list);
		if (i > 1)
		{
			tmp = (*list)->i;
			(*list)->i = (*list)->next->i;
			(*list)->next->i = tmp;
		}
		if (flag == A)
			write(1, "sa\n", 3);
		else if (flag == B)
			write(1, "sb\n", 3);
	}
}

void	push_exe(t_list **one, t_list **two, int flag)
{
	t_list	*tmp;
	t_list	*new;

	if (*one)
	{
		if (*two)
		{
			new = list_new_node((*one)->i);
			new->gen = (*one)->gen;
			list_add_front(two, new);
		}
		else
		{
			*two = list_new_node((*one)->i);
			(*two)->gen = (*one)->gen;
		}
		tmp = *one;
		*one = (*one)->next;
		free(tmp);
		if (flag == A)
			write(1, "pa\n", 3);
		else if (flag == B)
			write(1, "pb\n", 3);
	}
}

void	rotate_exe(t_list **list, int flag)
{
	t_list	*tmp;
	t_list	*new;

	if (*list)
	{
		new = list_new_node((*list)->i);
		new->gen = (*list)->gen;
		list_add_back(list, new);
		tmp = *list;
		*list = (*list)->next;
		free(tmp);
		if (flag == A)
			write(1, "ra\n", 3);
		else if (flag == B)
			write(1, "rb\n", 3);
	}
}

void	reverse_rotate_exe(t_list **list, int flag)
{
	t_list	*tmp;
	t_list	*tmp_to_free;
	t_list	*new;

	if (*list && list_size(*list) > 1)
	{
		tmp = *list;
		while ((*list)->next->next)
			*list = (*list)->next;
		new = list_new_node((*list)->next->i);
		new->gen = (*list)->next->gen;
		tmp_to_free = (*list)->next;
		(*list)->next = NULL;
		free(tmp_to_free);
		list_add_front(&tmp, new);
		*list = new;
		if (flag == A)
			write(1, "rra\n", 4);
		else if (flag == B)
			write(1, "rrb\n", 4);
	}
}
