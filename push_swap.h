#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include	<stdlib.h>

typedef struct	s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	int				data;
	int				comp;
}				t_list;

typedef struct s_stack
{
    t_list        *top;
    t_list        *bottom;
    int            count;
}                t_stack; 

t_list	*compression(t_list **list);
size_t	listsize(t_list *list);
void    rotate(t_stack *stack);
void    rev_rotate(t_stack *stack);
void    swap(t_stack *stack);
void    push(t_stack *src, t_stack *dst);
#endif