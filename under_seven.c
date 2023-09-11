#include	"libft/libft.h"
#include	"printf/ft_printf.h"
#include	"push_swap.h"

int find_max(t_stacks *stacks)
{
    t_list *tmp;
    int     max;

    max = stacks->stack_a->top->comp;
    tmp = stacks->stack_a->top;
    while (tmp->next != NULL)
    {
        if (max < tmp->comp)
            max = tmp->comp;
        tmp = tmp->next;
    }
    return (max);
}

void    sort_under_seven(t_stacks *stacks)
{
 //   printf("check max = %d\n", max);
    while (stacks->stack_a->count > 3)
        push_b(stacks);
  //  printf("a : %d %d %d\n", stacks->stack_a->top->comp, stacks->stack_a->top->next->comp, stacks->stack_a->bottom->comp);
    //printf("b : %d %d %d\n", stacks->stack_b->top->comp, stacks->stack_b->top->next->comp, stacks->stack_b->top->next->next->comp);
    sort_three_data(stacks->stack_a);
  //  printf("a : %d %d %d\n", stacks->stack_a->top->comp, stacks->stack_a->top->next->comp, stacks->stack_a->bottom->comp);
    sort_three_data_b(stacks->stack_b);
 //   printf("b : %d %d\n", stacks->stack_b->top->comp, stacks->stack_b->top->next->comp);
    while (stacks->stack_b->count != 0)
    {
        if (stacks->stack_a->top->comp > stacks->stack_b->top->comp)
            push_a(stacks);
        else if (stacks->stack_b->top->comp == find_max(stacks) + 1 && stacks->stack_a->top->comp == find_max(stacks))
        {
         //   printf("check\n");
            rotate_a(stacks);
            push_a(stacks);
        }
        else
        {
            rotate_a(stacks);
           // printf("now a %d %d\n b top %d\n", stacks->stack_a->top->comp, stacks->stack_a->top->next->comp, stacks->stack_b->top->comp);
        }
    }
    while (stacks->stack_a->top->comp != 0)
        rotate_a(stacks);
    return ;
}