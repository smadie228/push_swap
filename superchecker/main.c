/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smadie <smadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:33:54 by smadie            #+#    #+#             */
/*   Updated: 2022/03/11 20:38:52 by smadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list	*init_list(char **arr, int argc)
{
	int		i;
	t_list	*node;
	t_list	*head;

	i = 1;
	head = list_new_node(ft_atoi(arr[i++]));
	if (!head)
		return (NULL);
	while (i < argc)
	{
		node = list_new_node(ft_atoi(arr[i]));
		list_add_back(&head, node);
		i++;
	}
	return (head);
}

void	execute_other_commands(char **c, t_list **a, t_list **b, int i)
{
	if (c[i][0] == 's' && c[i][1] == 's' && c[i][2] == '\0')
		swap_ab(a, b);
	else if (c[i][0] == 'r' && c[i][1] == 'r' && c[i][2] == '\0')
		rotate_ab(a, b);
	else if (c[i][0] == 'r' && c[i][1] == 'r'
		&& c[i][2] == 'a' && c[i][3] == '\0')
		reverse_rotate_exe(a, -1);
	else if (c[i][0] == 'r' && c[i][1] == 'r'
		&& c[i][2] == 'b' && c[i][3] == '\0')
		reverse_rotate_exe(b, -1);
	else if (c[i][0] == 'r' && c[i][1] == 'r'
		&& c[i][2] == 'r' && c[i][3] == '\0')
		reverse_rotate_ab(a, b);
	else
		print_error();
}

void	execute_commands(char **c, t_list **a, t_list **b)
{
	int		i;

	i = 0;
	while (c[i])
	{
		if (c[i][0] == 's' && c[i][1] == 'a' && c[i][2] == '\0')
			swap_exe(a, -1);
		else if (c[i][0] == 's' && c[i][1] == 'b' && c[i][2] == '\0')
			swap_exe(b, -1);
		else if (c[i][0] == 'p' && c[i][1] == 'a' && c[i][2] == '\0')
			push_exe(b, a, -1);
		else if (c[i][0] == 'p' && c[i][1] == 'b' && c[i][2] == '\0')
			push_exe(a, b, -1);
		else if (c[i][0] == 'r' && c[i][1] == 'a' && c[i][2] == '\0')
			rotate_exe(a, -1);
		else if (c[i][0] == 'r' && c[i][1] == 'b' && c[i][2] == '\0')
			rotate_exe(b, -1);
		else
			execute_other_commands(c, a, b, i);
		i++;
	}
	free_array_lib(c);
}

void	read_commands(t_list **list)
{
	char	**commands;
	char	*str;
	char	*tmp;
	char	*res;
	t_list	*b;

	b = NULL;
	res = malloc(1);
	res[0] = 0;
	str = get_next_line(0);
	while (str)
	{
		tmp = res;
		res = ft_strjoin(res, str);
		free(tmp);
		free(str);
		str = get_next_line(0);
	}
	commands = ft_lib_split(res, '\n');
	free(res);
	execute_commands(commands, list, &b);
	final_check(list, &b);
}

int	main(int argc, char **argv)
{
	char	**arr;
	int		flag;
	t_list	*a_list;

	flag = 0;
	if (argc < 2)
		return (1);
	if (argc == 2)
	{
		arr = arg_parse(*(argv + 1), &argc);
		flag = 1;
	}
	else
		arr = argv;
	if (check_digit(arr, argc) || check_repeat(arr, argc)
		|| check_minmax(arr, argc))
		print_error();
	a_list = init_list(arr, argc);
	read_commands(&a_list);
	free_list(&a_list);
	if (flag)
		free_array(arr, argc);
}
