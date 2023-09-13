/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <hmakida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 23:17:47 by hmakida           #+#    #+#             */
/*   Updated: 2023/09/13 15:54:38 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdlib.h>

typedef struct s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	int				data;
	int				comp;
	int				group;
}				t_list;

typedef struct s_stack
{
	t_list		*top;
	t_list		*bottom;
	int			count;
}				t_stack;

typedef struct s_stacks
{
	t_stack		*stack_a;
	t_stack		*stack_b;
}				t_stacks;

t_list	*compression(t_list **list);
size_t	listsize(t_list *list);
void	rotate(t_stack *stack);
void	rotate_a(t_stacks *stacks);
void	rotate_b(t_stacks *stacks);
void	rotate_r(t_stacks *stacks);
void	rev_rotate(t_stack *stack);
void	rev_rotate_a(t_stacks *stacks);
void	rev_rotate_b(t_stacks *stacks);
void	rev_rotate_r(t_stacks *stacks);
void	swap(t_stack *stack);
void	push(t_stack *src, t_stack *dst);
void	push_a(t_stacks *stacks);
void	push_b(t_stacks *stacks);
void	swap_a(t_stacks *stacks);
void	swap_b(t_stacks *stacks);
void	swap_s(t_stacks *stacks);
void	sort_three_data(t_stacks *stacks);
void	sort_three_data_b(t_stacks *stacks);
void	sort_under_seven(t_stacks *stacks);
void	sort_over_seven(t_stacks *stacks);
int		find_max(t_stack *stack);
int		check_argv_one(char **argv);
int		check_argv_two(char **argv);
t_list	*create_list(int data);
#endif
