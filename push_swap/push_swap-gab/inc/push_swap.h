/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <gcrocett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:57:02 by gcrocett          #+#    #+#             */
/*   Updated: 2021/10/14 11:09:16 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define BUFFER_SIZE 64
# define SUCCESS 1
# define FINISH 0
# define ERROR -1

typedef struct s_Node
{
	int				data;
	int				index;
	struct s_Node	*next;
}t_Node;

void	print(t_Node *first);
t_Node	*ft_lstnew(int data);
int		ft_error(void);
void	ft_lstadd_front(t_Node **lst, t_Node *new);
void	swap_data(int *a, int *b);
void	delete_first_node(t_Node **Stack);
void	delete_last_node(t_Node **Stack);
void	swap_nodes(t_Node **Stack, int i);
void	push_node(t_Node **dest, t_Node **source, int i);
void	reverse_rotate(t_Node **Stack, int i);
void	rotate_stack(t_Node **Stack, int i);
int		ft_atoi(char *str);
int		ft_isdigit(int c);
int		ft_isspace(int c);
long	ft_atol(const char *s);
int		check_duplicate_arr(int *arr, int argc);
int		check_duplicate(int argc, char **argv);
int		is_arg_number(char *str);
int		check_integers(int argc, char **argv);
int		check_arguments(int argc, char **argv);
void	create_stack(int argc, char **argv, t_Node **Stack);
char	**ft_split(const char *s, char c);
int		ft_count_words(const char *s, char c);
char	**ft_shift(int argc, char **argv);
int		list_sorted(t_Node **Stack);
void	parse_alg(t_Node **StackA, t_Node **StackB);
void	sort_two(t_Node **StackA);
void	sort_three(t_Node **StackA);
void	sort_five(t_Node **StackA, t_Node **StackB);
void	sort_twenty(t_Node **StackA, t_Node **StackB);
void	sort_fifty(t_Node **StackA, t_Node **StackB);
void	sort_hundred(t_Node **StackA, t_Node **StackB);
void	sort_twofifty(t_Node **StackA, t_Node **StackB);
void	sort_fivehundred(t_Node **StackA, t_Node **StackB);
void	sort_plus(t_Node **StackA, t_Node **StackB);
int		stack_len(t_Node **Stack);
int		smallest_pos(t_Node **Stack);
void	ra_rra_pos(t_Node **a, int pos);
void	set_index(t_Node **Stack);
void	pushback_all(t_Node **StackA, t_Node **StackB);
int		compare_smallest_pos(t_Node **Stack, int chunk);
void	inizialize_stack(int argc, char **argv, int i);
void	do_operations(t_Node **StackA, t_Node **StackB);
void	free_stacks(t_Node **StackA, t_Node **StackB);
void	null_stack(t_Node **StackA, t_Node **StackB);
void	free_argv(int argc, char **argv);
void	*ft_calloc(size_t nitems, size_t size);
int		check_empty(char *argv);
int		ft_strcmp(char *s1, char *s2);
int		get_next_line(int fd, char **line);
size_t	ft_strlen_c(char *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_is_in_str(char c, char *str);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
