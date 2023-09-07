/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <hmakida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 23:17:23 by hmakida           #+#    #+#             */
/*   Updated: 2023/09/07 15:27:48 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "libft/libft.h"
#include    "printf/ft_printf.h"
#include    "push_swap.h"

void	swap(t_stack *stack)
{
	t_list	*tmp_top;
	t_list	*tmp;

	if (stack->count <= 1)
		return ;
	tmp_top = stack->top;
	//printf("tmp_top %p\n", tmp_top->prev);
	tmp = stack->top->next->next;
//	printf("tmp %p\n", tmp);
	stack->top = stack->top->next;
	//printf("check1\n");
	stack->top->prev = NULL;
	//printf("check2\n");
	stack->top->next = tmp_top;
	//printf("check3\n");
	tmp_top->prev = stack->top;
	//printf("check4\n");
	tmp_top->next = tmp;

	//printf("check stack->top->comp %d\n", stack->top->comp);
	tmp->prev = tmp_top;
	//printf("ここでダメそう");
	return ;
}

void	swap_a(t_stacks *stacks)
{
	swap(stacks->stack_a);
	ft_printf("sa\n");
	return ;
}

void	swap_b(t_stacks *stacks)
{
	swap(stacks->stack_b);
	ft_printf("sb\n");
	return ;
}

void	swap_s(t_stacks *stacks)
{
	swap(stacks->stack_a);
	swap(stacks->stack_b);
	ft_printf("ss\n");
	return ;
}
