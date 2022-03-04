/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smadie <smadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:15:36 by smadie            #+#    #+#             */
/*   Updated: 2022/03/04 20:03:18 by smadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h> // exit
#include <stdio.h> // printf

// начнем со структур?? долбанный массив якобы для упращения проверки и ловли Error
typedef struct s_array // создаем массив в структуре
{
	int	a[10000];
	int count_element;
}	t_array;

typedef struct s_stack
{
	int number;
	struct s_stack *next;
}	t_stack;

typedef struct s_stacks
{
	t_stack *a;
	t_stack *b;
}	t_stacks;

// чел ты издиваешься закидывать всю либу???
char	**ft_split(char	const *s, char c);
int	ft_atoi(const char *str);
//////////////////////

// пару функции
void	ft_stacking(t_array *new, int *buff, int count);

#endif
