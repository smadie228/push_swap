/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smadie <smadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:33:54 by smadie            #+#    #+#             */
/*   Updated: 2022/03/11 20:38:14 by smadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define MY_INT_MIN -2147483648
# define MY_INT_MAX 2147483647
# define A 666
# define B 777
# define BUFFER_SIZE 10

typedef struct s_list
{
	int				i;
	int				gen;
	struct s_list	*next;
}				t_list;

char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c, int *argc);
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
int		check_digit(char **arr, int argc);
int		check_minmax(char **arr, int argc);
int		check_repeat(char **arr, int argc);
void	print_error(void);
t_list	*list_new_node(int i);
void	list_add_front(t_list **list, t_list *node);
void	list_add_back(t_list **list, t_list *node);
int		list_size(t_list *list);
void	free_list(t_list **a);
int		ft_atoi(const char *s);
void	swap_exe(t_list **list, int flag);
void	swap_ab(t_list **a, t_list **b);
void	push_exe(t_list **one, t_list **two, int flag);
void	rotate_exe(t_list **list, int flag);
void	rotate_ab(t_list **a, t_list **b);
void	reverse_rotate_exe(t_list **list, int flag);
void	reverse_rotate_ab(t_list **a, t_list **b);
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	**ft_lib_split(char const *s, char c);
char	**arg_parse(char *arg, int *argc);
void	free_list(t_list **a);
void	free_array(char **arr, int argc);
void	free_array_lib(char **arr);
int		check_is_sort(t_list *a);
void	final_check(t_list **a, t_list **b);

#endif
