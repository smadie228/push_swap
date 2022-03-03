/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smadie <smadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:01:13 by smadie            #+#    #+#             */
/*   Updated: 2022/03/03 19:04:33 by smadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_array // создаем массив в структуре
{
	int	a[10000];
	int count_element;
}	t_array;


int	ft_countword(char *s)
{
	int count;

	count = 0;
	while (*s)
	{
		if (*s != ' ' && *s != '\t')
		{
			count++;
			while ((*s != ' ' && *s != '\t') && *s != '\0')
				s++;
		}
		else
			s++;
	}
	return (count);
}

void create_array(int argc, char **argv, t_array *new)
{
	int p;
	int i;
	int count_element;
	int		*buff; // созданеи буфера
	char	**mass;

	i = 1;
	count_element = 0;
	while (argc > 1)
	{
		p = 0;
		count_element = ft_countword(argv[i]);
		mass = ft_split(argv[i], count_element);
		// нужна ли здесь проверка на выделение памяти под buf??? естьб же проверка в самом сплите buff = malloc
		while (count_element > p)
		{
			buff[p] = ft_atoi(mass[p]);
			// free?
		}
		//free?
		printf ("%d", buff[p]);
		i++;
	}
}

int main(int argc, char **argv)
{
	t_array *new;

	if (argc < 2)
		exit (1);

	create_array(argc, argv, new);

}
