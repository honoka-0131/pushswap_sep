/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over_seven.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <hmakida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 23:02:23 by hmakida           #+#    #+#             */
/*   Updated: 2023/09/11 18:38:10 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "libft/libft.h"
#include    "printf/ft_printf.h"
#include    "push_swap.h"

void    sort_over_seven(t_stacks *stacks)
{
    int num;
    int median;
    int count;
    int i;
    int group;

    group = 1;
    num = 50;
    median = stacks->stack_a->count / 2;
    i = 0;
    while (stacks->stack_a->count > 1)
    {
        count = stacks->stack_a->count;
        while (count > i)
        {
            if (stacks->stack_a->top->comp >= median && median + num >= stacks->stack_a->top->comp)
            {
                stacks->stack_a->top->group = group;
                push_b(stacks);
            }
            else if (stacks->stack_a->top->comp >= median - num && median >= stacks->stack_a->top->comp)
            {
                stacks->stack_a->top->group = group * -1;
                push_b(stacks);
                rotate_b(stacks);
            }
            else
                rotate_a(stacks);
            i ++;
        }
        i = 0;
        num += 50;
    } 
    return ;
}