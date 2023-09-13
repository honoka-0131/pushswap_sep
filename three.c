/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <hmakida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:01:06 by hmakida           #+#    #+#             */
/*   Updated: 2023/09/13 16:30:36 by hmakida          ###   ########.fr       */
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
	if (stacks->b->count == 1)
		return ;
	if (stacks->b->count == 2
		&& stacks->b->top->comp > stacks->b->bottom->comp)
	{
		sort_two_data(stacks->b, -1);
		return ;
	}
	else if (stacks->b->count == 2)
		return ;
	while (!(stacks->b->top->comp < stacks->b->top->next->comp
			&& stacks->b->top->next->comp < stacks->b->bottom->comp))
	{
		if (stacks->b->top->next->comp > stacks->b->top->comp
			&& stacks->b->top->next->comp > stacks->b->bottom->comp)
			rev_rotate_b(stacks);
		else if (stacks->b->top->next->comp < stacks->b->top->comp
			&& stacks->b->top->comp > stacks->b->bottom->comp)
			rotate_b(stacks);
		else if (stacks->b->top->comp > stacks->b->top->next->comp
			&& stacks->b->top->comp < stacks->b->bottom->comp)
			swap_b(stacks);
	}
	return ;
}

void	sort_three_data(t_stacks *stacks)
{
	if (stacks->a->count == 2
		&& stacks->a->top->comp > stacks->a->bottom->comp)
	{
		sort_two_data(stacks->a, 1);
		return ;
	}
	while (!(stacks->a->top->comp < stacks->a->top->next->comp
			&& stacks->a->top->next->comp < stacks->a->bottom->comp))
	{
		if (stacks->a->top->next->comp > stacks->a->top->comp
			&& stacks->a->top->next->comp > stacks->a->bottom->comp)
			rev_rotate_a(stacks);
		else if (stacks->a->top->next->comp < stacks->a->top->comp
			&& stacks->a->top->comp > stacks->a->bottom->comp)
			rotate_a(stacks);
		else if (stacks->a->top->comp > stacks->a->top->next->comp
			&& stacks->a->top->comp < stacks->a->bottom->comp)
			swap_a(stacks);
	}
	return ;
}
