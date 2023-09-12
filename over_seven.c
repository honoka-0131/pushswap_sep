/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over_seven.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <hmakida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 23:02:23 by hmakida           #+#    #+#             */
/*   Updated: 2023/09/12 15:32:38 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "libft/libft.h"
#include    "printf/ft_printf.h"
#include    "push_swap.h"

void    sort_over_seven(t_stacks *stacks)
{
    int     num;
    int     median;
    int     count;
    int     i;
    int     group;
    int     max;
    t_list  *tmp;

    group = 1;
    num = 10;
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
        num += 10;
        group ++;
    }
    while (stacks->stack_b->count > 1)
    {
        tmp = stacks->stack_b->top;
     //   printf("count: a %d, b %d\n", stacks->stack_a->count, stacks->stack_b->count);
        group = tmp->group;
        while (stacks->stack_b->count > 0 && tmp->group == group)
        {
            max = find_max(stacks->stack_b);
     //       printf("max = %d\n", max);
            if (tmp->comp == max)
            {
                while (stacks->stack_b->top->comp != max)
                    rotate_b(stacks);
                push_a(stacks);
                tmp = stacks->stack_b->top;
            }
            else
                tmp = tmp->next;
        }
   //     printf("now tmp = %d, group %d\n", tmp->comp, tmp->group);
        tmp = stacks->stack_b->bottom;
        while (stacks->stack_b->count > 0 && tmp->group == group)
        {
            max = find_max(stacks->stack_b);
            //printf("max = %d\n", max);
            if (tmp->comp == max)
            {
              //  printf("入ってるかチェック\n");
                while (stacks->stack_b->top->comp != max)
                    rev_rotate_b(stacks);
              //  printf("stackB top %d\n", stacks->stack_b->top->comp);
                push_a(stacks);
                tmp = stacks->stack_b->bottom;
            }
            else
                tmp = tmp->prev;
 //           printf("check tmp = %d, group %d\n", tmp->comp, tmp->group);
        }
    }
    return ;
}