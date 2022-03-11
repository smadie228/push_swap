/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smadie <smadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:33:54 by smadie            #+#    #+#             */
/*   Updated: 2022/03/11 20:38:45 by smadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list	*list_new_node(int i)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->i = i;
	new->gen = 0;
	new->next = NULL;
	return (new);
}

void	list_add_front(t_list **list, t_list *node)
{
	t_list	*head;

	head = *list;
	if (node && head)
	{
		node->next = head;
		*list = node;
	}
}

void	list_add_back(t_list **list, t_list *node)
{
	t_list	*head;

	head = *list;
	if (node && head)
	{
		while (head->next)
			head = head->next;
		head->next = node;
	}
}

int	list_size(t_list *list)
{
	int		count;

	count = 0;
	while (list)
	{
		count++;
		list = list->next;
	}
	return (count);
}

void	free_list(t_list **a)
{
	t_list	*tmp;

	while (*a)
	{
		tmp = *a;
		*a = (*a)->next;
		free(tmp);
	}
}
