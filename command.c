#include    "libft/libft.h"
#include    "printf/ft_printf.h"
#include    "push_swap.h"

void    rotate(t_stack *stack)
{
    t_list  *tmp_top;
    t_list  *tmp_bottom;
    t_list  *new_top;
    t_list  *new_bottom;

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

t_stack *make_newstack(t_list *list)
{
    t_stack  *new;

    new = malloc(sizeof(t_stack));
    new->top = list;
    new->bottom = list;
    new->count = 1;
    new->top->next = NULL;
    return (new);
}

void    push(t_stack *src, t_stack *dst)
{
    t_list  *tmp;
    t_list  *tmp_two;

    if (dst == NULL)
    {
        tmp = src->top->next;
        tmp_two = src->top->next->next;
        dst = make_newstack(src->top);
        src->count --;
        src->top = tmp;
        src->top->next = tmp_two;
        src->top->prev = NULL;
        tmp->prev = src->top;
    }
    return ;
}