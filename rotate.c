/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 23:10:46 by hmakida           #+#    #+#             */
/*   Updated: 2023/09/05 23:10:50 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "libft/libft.h"
#include    "printf/ft_printf.h"
#include    "push_swap.h"

void	rotate(t_stack *stack)
{
	t_list	*tmp_top;
	t_list	*tmp_bottom;
	t_list	*new_top;
	t_list	*new_bottom;

	if (stack->count <= 1)
		return ;
	tmp_top = stack->top;
	tmp_bottom = stack->bottom;
	new_top = stack->top->next;
	new_bottom = stack->top;
	stack->top = new_top;
	new_top->prev = NULL;
	stack->bottom = new_bottom;
	stack->bottom->next = NULL;
	stack->bottom->prev = tmp_bottom;
	return ;
}

void	rotate_a(t_stacks *stacks)
{
	rotate(stacks->stack_a);
	ft_printf("ra\n");
	return ;
}

void	rotate_b(t_stacks *stacks)
{
	rotate(stacks->stack_b);
	ft_printf("rb\n");
	return ;
}

void	rotate_r(t_stacks *stacks)
{
	rotate(stacks->stack_a);
	rotate(stacks->stack_b);
	ft_printf("rr\n");
	return ;
}
