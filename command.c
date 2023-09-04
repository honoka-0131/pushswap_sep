#include    "libft/libft.h"
#include    "printf/ft_printf.h"
#include    "push_swap.h"

void    rotate(t_stack *stack)
{
    t_list  *tmp_top;
    t_list  *tmp_bottom;
    t_list  *new_top;
    t_list  *new_bottom;

    if (stack->count <= 1)
        return ;
    tmp_top = stack->top;
    tmp_bottom = stack->bottom;
    new_top = stack->top->next;
    new_bottom = stack->top;
    stack->top = new_top;
    new_top->prev = NULL;
    stack->bottom = new_bottom;
    stack->bottom->next = NULL;
    stack->bottom->prev = tmp_bottom;
    return ;
}

void    rev_rotate(t_stack *stack)
{
    t_list  *tmp_top;
    t_list  *tmp_bottom;
    t_list  *new_top;
    t_list  *new_bottom;

    if (stack->count <= 1)
        return ;
    tmp_top = stack->top;
    tmp_bottom = stack->bottom;
    new_top = stack->bottom;
    new_bottom = stack->bottom->prev;
    stack->top = new_top;
    new_top->prev = NULL;
    stack->top->next = tmp_top;
    stack->bottom = new_bottom;
    stack->bottom->next = NULL;
    return ;
}

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

void    push(t_stack *src, t_stack *dst)
{
    t_list  *src_newtop;

    if (src->count == 0)
        return ;
    src_newtop = src->top->next;
    src->count --;
    src->top->next = dst->top;
    dst->top = src->top;
    dst->count ++;
    if (dst->count == 1)
        dst->bottom = dst->top;
    src->top = src_newtop;
    src->top->prev = NULL;
    return ;
}