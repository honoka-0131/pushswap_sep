/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <hmakida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:01:06 by hmakida           #+#    #+#             */
/*   Updated: 2023/09/13 14:27:04 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft/libft.h"
#include	"printf/ft_printf.h"
#include	"push_swap.h"

void	sort_two_data(t_stack *stack, int flag)
{
	if (stack->top->comp > stack->bottom->comp)
	{
		t_list	*tmp_top;

		tmp_top = stack->top;
		stack->top = stack->bottom;
		stack->bottom = tmp_top;
		stack->top->prev = NULL;
		stack->top->next = stack->bottom;
		stack->bottom->prev = stack->top;
		stack->bottom->next = NULL;
		if (flag == -1)
			ft_printf("sb\n");
		else if (flag == 1)
			ft_printf("sa\n");
	}
	return ;
}

void	sort_three_data_b(t_stacks *stacks)
{
	if (stacks->stack_b->count == 1)
		return ;
	if (stacks->stack_b->count == 2
		&& stacks->stack_b->top->comp > stacks->stack_b->bottom->comp)
	{
		sort_two_data(stacks->stack_b, -1);
		return ;
	}
	else if (stacks->stack_b->count == 2)
		return ;
	while (!(stacks->stack_b->top->comp < stacks->stack_b->top->next->comp
			&& stacks->stack_b->top->next->comp < stacks->stack_b->bottom->comp))
	{
		if (stacks->stack_b->top->next->comp > stacks->stack_b->top->comp
			&& stacks->stack_b->top->next->comp > stacks->stack_b->bottom->comp)
			rev_rotate_b(stacks);
		else if (stacks->stack_b->top->next->comp < stacks->stack_b->top->comp
			&& stacks->stack_b->top->comp > stacks->stack_b->bottom->comp)
			rotate_b(stacks);
		else if (stacks->stack_b->top->comp > stacks->stack_b->top->next->comp
			&& stacks->stack_b->top->comp < stacks->stack_b->bottom->comp)
			swap_b(stacks);
	}
	return ;
}

void	sort_three_data(t_stacks *stacks)
{
	if (stacks->stack_a->count == 2
		&& stacks->stack_a->top->comp > stacks->stack_a->bottom->comp)
	{
		sort_two_data(stacks->stack_a, 1);
		return ;
	}
	while (!(stacks->stack_a->top->comp < stacks->stack_a->top->next->comp
			&& stacks->stack_a->top->next->comp < stacks->stack_a->bottom->comp))
	{
		if (stacks->stack_a->top->next->comp > stacks->stack_a->top->comp
			&& stacks->stack_a->top->next->comp > stacks->stack_a->bottom->comp)
			rev_rotate_a(stacks);
		else if (stacks->stack_a->top->next->comp < stacks->stack_a->top->comp
			&& stacks->stack_a->top->comp > stacks->stack_a->bottom->comp)
			rotate_a(stacks);
		else if (stacks->stack_a->top->comp > stacks->stack_a->top->next->comp
			&& stacks->stack_a->top->comp < stacks->stack_a->bottom->comp)
			swap_a(stacks);
	}
	return ;
}
