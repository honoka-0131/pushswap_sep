#include    "libft/libft.h"
#include    "printf/ft_printf.h"
#include    "push_swap.h"

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