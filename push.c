/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <hmakida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 23:02:23 by hmakida           #+#    #+#             */
/*   Updated: 2023/09/11 15:06:07 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "libft/libft.h"
#include    "printf/ft_printf.h"
#include    "push_swap.h"

void	push(t_stack *src, t_stack *dst)
{
	t_list	*src_newtop;

	if (src->count == 0)
		return ;
	src_newtop = src->top->next;
	src->count --;
	src->top->next = dst->top;
	dst->top = src->top;
	dst->count ++;
	if (dst->count == 1)
		dst->bottom = dst->top;
	if (dst->count == 2)
	{
		dst->bottom->prev = dst->top;
	}
	if (src->count != 0)
	{
		src->top = src_newtop;
		src->top->prev = NULL;
	}
	return ;
}

void	push_a(t_stacks *stacks)
{
	push(stacks->stack_b, stacks->stack_a);
	ft_printf("pa\n");
	return ;
}

void	push_b(t_stacks *stacks)
{
	push(stacks->stack_a, stacks->stack_b);
	ft_printf("pb\n");
	return ;
}
