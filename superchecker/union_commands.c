/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smadie <smadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:33:54 by smadie            #+#    #+#             */
/*   Updated: 2022/03/11 20:39:00 by smadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_ab(t_list **a, t_list **b)
{
	if (*a && *b)
	{
		swap_exe(a, -1);
		swap_exe(b, -1);
	}
}

void	rotate_ab(t_list **a, t_list **b)
{
	if (*a && *b)
	{
		rotate_exe(a, -1);
		rotate_exe(b, -1);
	}
}

void	reverse_rotate_ab(t_list **a, t_list **b)
{
	if (*a && *b)
	{
		reverse_rotate_exe(a, -1);
		reverse_rotate_exe(b, -1);
	}
}
