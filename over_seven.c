/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over_seven.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <hmakida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 23:02:23 by hmakida           #+#    #+#             */
/*   Updated: 2023/09/13 16:27:17 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "libft/libft.h"
#include    "printf/ft_printf.h"
#include    "push_swap.h"

void	helper(t_stacks *stacks, int count, int group, int median, int num)
{
	int	i;

	i = 0;
	while (count > i)
	{
		if (stacks->a->top->comp >= median
			&& median + num >= stacks->a->top->comp)
		{
			stacks->a->top->group = group;
			push_b(stacks);
			if (stacks->b->top->comp < stacks->b->top->comp)
				swap_b(stacks);
		}
		else if (stacks->a->top->comp >= median - num
			&& median >= stacks->a->top->comp)
		{
			stacks->a->top->group = group * -1;
			push_b(stacks);
			rotate_b(stacks);
		}
		else
			rotate_a(stacks);
		i ++;
	}
}

int	rb_and_pa(t_stacks *stacks, int group, t_list *tmp, int max)
{
	tmp = stacks->b->top;
	group = tmp->group;
	while (stacks->b->count > 0 && tmp->group == group)
	{
		max = find_max(stacks->b);
		if (tmp->comp == max)
		{
			while (stacks->b->top->comp != max)
				rotate_b(stacks);
			push_a(stacks);
			tmp = stacks->b->top;
		}
		else
			tmp = tmp->next;
	}
	return (group);
}

int	rrb_and_pa(t_stacks *stacks, int group, t_list *tmp, int max)
{
	tmp = stacks->b->bottom;
	while (stacks->b->count > 0 && tmp->group == group)
	{
		max = find_max(stacks->b);
		if (tmp->comp == max)
		{
			while (stacks->b->top->comp != max)
				rev_rotate_b(stacks);
			push_a(stacks);
			tmp = stacks->b->bottom;
		}
		else
			tmp = tmp->prev;
	}
	return (group);
}

void	helper_two(t_stacks *stacks, int group)
{
	t_list	*tmp;
	int		max;

	tmp = NULL;
	max = 0;
	while (stacks->b->count > 1)
	{
		group = rb_and_pa(stacks, group, tmp, max);
		group = rrb_and_pa(stacks, group, tmp, max);
	}
	return ;
}

void	sort_over_seven(t_stacks *stacks)
{
	int		num;
	int		median;
	int		count;
	int		group;

	group = 1;
	num = stacks->a->count / 10;
	median = stacks->a->count / 2;
	while (stacks->a->count > 1)
	{
		count = stacks->a->count;
		helper(stacks, count, group, median, num);
		num += 10;
		group ++;
	}
	helper_two(stacks, group);
	return ;
}
