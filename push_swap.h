/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smadie <smadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:15:36 by smadie            #+#    #+#             */
/*   Updated: 2022/03/08 20:56:24 by smadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h> // exit
#include <stdio.h> // printf
#include <unistd.h> // write


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
	int	count_a;
	int count_b;
	int min;
	int max;
	int med;
	t_stack *a;
	t_stack *b;
}	t_stacks;

// чел ты издиваешься закидывать всю либу???
char	**ft_split(char	const *s, char c);
int	ft_atoi(const char *str);
//////////////////////

// пару функции для array
int	ft_countword(char *s);
void	ft_stacking(t_array *new, int *buff, int count);
void	create_array(int argc, char **argv, t_array *new);

//пару функции для создания листов и их инициализации
t_stack *ft_create_stack(int *buff, int count);
void ft_create_stacks(t_array *new, t_stacks *stacks);


//наши операции часть 1
void ft_sa(t_stack *a, int i);
void ft_sb(t_stack *b, int i);
void ft_ss(t_stacks *s, int i);
void ft_pa(t_stacks *s, int i);
void ft_pb(t_stacks *s, int i);

//наши операции часть 2
void ft_ra(t_stack **a, int i);
void ft_rb(t_stack **b, int i);
void ft_rr(t_stacks *s, int i);
void ft_rra(t_stack **a, int i);
void ft_rrb(t_stack **b, int i);

// quick_sort
void ft_quick_sort(int *array, int firsr_element, int last_element);
int ft_part(int *array, int start, int end);

// работа с дубликатами и с массивом
int *ft_intcopy(int *dst, int *src, int count);
void ft_search_duplicate(int *duplicate, int count);
void ft_duplicate(t_array *new, t_stacks *stacks);

#endif
