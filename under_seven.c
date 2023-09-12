/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_seven.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <hmakida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:05:14 by hmakida           #+#    #+#             */
/*   Updated: 2023/09/12 14:57:53 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft/libft.h"
#include	"printf/ft_printf.h"
#include	"push_swap.h"

int	find_max(t_stack *stack)
{
	t_list	*tmp;
	int		max;

	max = stack->top->comp;
	tmp = stack->top;
	while (tmp->next != NULL)
	{
		if (max < tmp->comp)
			max = tmp->comp;
		tmp = tmp->next;
	}
	if (max < tmp->comp)
			max = tmp->comp;
	return (max);
}

void    sort_under_seven(t_stacks *stacks)
{
	while (stacks->stack_a->count > 3)
		push_b(stacks);
	sort_three_data(stacks->stack_a);
	sort_three_data_b(stacks->stack_b);
	while (stacks->stack_b->count != 0)
	{
		if (stacks->stack_a->top->comp > stacks->stack_b->top->comp)
			push_a(stacks);
		else if (stacks->stack_b->top->comp == find_max(stacks->stack_a) + 1 
			&& stacks->stack_a->top->comp == find_max(stacks->stack_a))
		{
			rotate_a(stacks);
			push_a(stacks);
		}
		else
		{
			rotate_a(stacks);
		}
	}
	while (stacks->stack_a->top->comp != 0)
		rotate_a(stacks);
	return ;
}
