/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <hmakida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 23:02:23 by hmakida           #+#    #+#             */
/*   Updated: 2023/09/11 12:53:13 by hmakida          ###   ########.fr       */
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
//	printf("dstcount %d\n", dst->count);
	if (dst->count == 1)
	{
		dst->bottom = dst->top;
	//	printf("ここのifcheck\n");
	}
	if (dst->count == 2)
	{
		dst->bottom->prev = dst->top;
	}
//	printf("check dst->bottom %d\n", dst->bottom->comp);
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
//	printf("check pb %d\n", stacks->stack_b->top->comp);
	return ;
}
