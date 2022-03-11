/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smadie228 <smadie228@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:15:36 by smadie            #+#    #+#             */
/*   Updated: 2022/03/11 18:13:02 by smadie228        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> // exit
# include <stdio.h> // printf
# include <unistd.h> // write

typedef struct s_array // создаем массив в структуре
{
	int	a[10000];
	int	count_element;
}	t_array;

typedef struct s_stack
{
	int				number;
	int				step;
	int				rotate;
	struct s_stack	*next;
}	t_stack;

typedef struct s_stacks
{
	int			count_a;
	int			count_b;
	int			min;
	int			max;
	int			med;
	t_stack		*a;
	t_stack		*b;
}	t_stacks;

typedef struct s_steps
{
	int	count_a;
	int	count_b;
	int	dest_a;
	int	dest_b;
}	t_steps;

// либа укороченная
char	**ft_split(char	const *s, char c);
long long int		ft_atoi(const char *str);
void	ft_error(void);
void	ft_putchar(char c);
void	ft_putstr(char *s);
//////////////////////

// пару функции для array
int		ft_countword(char *s);
void	ft_stacking(t_array *new, long long int *buff, int count);
void	create_array(int argc, char **argv, t_array *new);
void	ft_valid_max_min_int(long long int new);

//пару функции для создания листов и их инициализации
t_stack	*ft_create_stack(int *buff, int count);
void	ft_create_stacks(t_array *new, t_stacks *stacks);
void	ft_free_stacks(t_stacks *stacks);
void	ft_null_stack(t_stacks *stacks, t_array *new);

//наши операции часть 1
void	ft_sa(t_stack *a, int i);
void	ft_sb(t_stack *b, int i);
void	ft_ss(t_stacks *s, int i);
void	ft_pa(t_stacks *s, int i);
void	ft_pb(t_stacks *s, int i);

//наши операции часть 2
void	ft_ra(t_stack **a, int i);
void	ft_rb(t_stack **b, int i);
void	ft_rr(t_stacks *s, int i);
void	ft_rra(t_stack **a, int i);
void	ft_rrb(t_stack **b, int i);
void	ft_rrr(t_stacks *s, int i);

// quick_sort
void	ft_quick_sort(int *array, int firsr_element, int last_element);
int		ft_part(int *array, int start, int end);
int		ft_is_sorted(t_array *new);

// работа с дубликатами и с массивом
int		*ft_intcopy(int *dst, int *src, int count);
void	ft_search_duplicate(int *duplicate, int count);
void	ft_duplicate(t_array *new, t_stacks *stacks);

// сортировка 3 или 5 элементов
int		ft_max(t_stack *s);
void	ft_3_elementsort(t_stacks *stacks);
void	ft_5_elementsort(t_stacks *stacks);

// нахождение лучшшего места для вставки и ее обработка

void	ft_help_finding_place(t_stacks *s, t_stack *b, int *action, int *buff);
int		ft_finding_place(t_stacks *s, t_stack *b, t_steps *steps, int min);
int		ft_smaller_element_detection(t_stack *a, int buff, int src);
int		ft_count_to_min(t_stack *a, int min);

//глобальная сортировка > 5 элеменов

void	ft_max_sort(t_stacks *stacks);
void	ft_begin_sort(t_stacks *stacks);
void	ft_steps_pointed(t_stack *b, int count);
void	ft_min_step(t_stacks *stacks, t_steps *steps);
void	ft_instruction_step(t_stacks *stacks, t_steps *steps);

// проверка на валидность
int		ft_spaces(char *str);
void	ft_validation_number(char *str);
void	ft_validation_str(char *str);
int		ft_validation(int argc, char **argv);

#endif
