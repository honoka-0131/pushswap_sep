/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 23:05:02 by hmakida           #+#    #+#             */
/*   Updated: 2023/09/05 23:06:18 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "libft/libft.h"
#include    "printf/ft_printf.h"
#include    "push_swap.h"

void	rev_rotate(t_stack *stack)
{
	t_list	*tmp_top;
	t_list	*tmp_bottom;
	t_list	*new_top;
	t_list	*new_bottom;

	if (stack->count <= 1)
		return ;
	tmp_top = stack->top;
	tmp_bottom = stack->bottom;
	new_top = stack->bottom;
	new_bottom = stack->bottom->prev;
	stack->top = new_top;
	new_top->prev = NULL;
	stack->top->next = tmp_top;
	stack->bottom = new_bottom;
	stack->bottom->next = NULL;
	return ;
}

void	rev_rotate_a(t_stacks *stacks)
{
	rev_rotate(stacks->stack_a);
	ft_printf("rra\n");
	return ;
}

void	rev_rotate_b(t_stacks *stacks)
{
	rev_rotate(stacks->stack_b);
	ft_printf("rrb\n");
	return ;
}

void	rev_rotate_r(t_stacks *stacks)
{
	rev_rotate(stacks->stack_a);
	rev_rotate(stacks->stack_b);
	ft_printf("rrr\n");
	return ;
}
