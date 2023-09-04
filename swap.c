#include    "libft/libft.h"
#include    "printf/ft_printf.h"
#include    "push_swap.h"

void    swap(t_stack *stack)
{
    t_list  *tmp_top;
    t_list  *tmp;

    if (stack->count <= 1)
        return ;
    tmp_top = stack->top;
    tmp = stack->top->next->next;
    stack->top = stack->top->next;
    stack->top->prev = NULL;
    stack->top->next = tmp_top;
    tmp_top->prev = stack->top;
    tmp_top->next = tmp;
    tmp->prev = tmp_top;
    return ;
}

void    swap_a(t_stacks *stacks)
{
    swap(stacks->stack_a);
    ft_printf("sa\n");
    return ;
}

void    swap_b(t_stacks *stacks)
{
    swap(stacks->stack_b);
    ft_printf("sb\n");
    return ;
}

void    swap_s(t_stacks *stacks)
{
    swap(stacks->stack_a);
    swap(stacks->stack_b);
    ft_printf("ss\n");
    return ;
}