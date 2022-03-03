/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smadie <smadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 21:30:25 by smadie            #+#    #+#             */
/*   Updated: 2022/03/03 19:10:38 by smadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_escape(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' || str[i] = '\t' || str[i] == 'v'
			|| str[i] == ' ' || str[i] == '\r' || str[i] == '\f')
			i++;
		else
			return (1);
	}
	return (0);
}

int ft_validation(int argc, char **argv)
{
	int i;
	int ok;

	i = 0;
	while(i < argc)
	{
		if (ft_escape(argv[i])
		{
			//здесь должна быть проверка на валидность если все нормально вернет 1
			ok = 1;
		}
		i++;
	}
	return (ok);
}


int main(int argc, char **argv)
{
	t_data		*new;
	t_stacks	*stacks;
	if (argc < 2)
		exit (1);
	if (!(stacks = (t_stacks *)malloc(sizeof(t_stacks))))
		exit (1);
	if (ft_validation(argc, argv))
	{
		ft_create_array(argc, argv, new);
	}
}

typedef struck s_strucks
{

}
