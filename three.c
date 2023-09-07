#include	"libft/libft.h"
#include	"printf/ft_printf.h"
#include	"push_swap.h"

void	sort_two_data(t_stacks *stacks)
{
	if (stacks->stack_a->top->comp > stacks->stack_a->bottom->comp)
	{
		t_list	*tmp_top;

		tmp_top = stacks->stack_a->top;
		stacks->stack_a->top = stacks->stack_a->bottom;
		stacks->stack_a->bottom = tmp_top;
		stacks->stack_a->top->prev = NULL;
		stacks->stack_a->top->next = stacks->stack_a->bottom;
		stacks->stack_a->bottom->prev = stacks->stack_a->top;
		stacks->stack_a->bottom->next = NULL;
		ft_printf("sa\n");
	}
	return ;
}

void	sort_three_data(t_stacks *stacks)
{
	if (stacks->stack_a->count == 2)
	{
		sort_two_data(stacks);
		printf("check %d %d\n", stacks->stack_a->bottom->prev->comp, stacks->stack_a->top->next->comp);
		return ;
	}
	while (!(stacks->stack_a->top->comp < stacks->stack_a->top->next->comp && stacks->stack_a->top->next->comp < stacks->stack_a->bottom->comp))
	{
		if (stacks->stack_a->top->next->comp > stacks->stack_a->top->comp && stacks->stack_a->top->next->comp > stacks->stack_a->bottom->comp)
		{
			rev_rotate_a(stacks);
		}
        else if (stacks->stack_a->top->next->comp < stacks->stack_a->top->comp && stacks->stack_a->top->comp > stacks->stack_a->bottom->comp)
		{
			rotate_a(stacks);
		}
		else if (stacks->stack_a->top->comp > stacks->stack_a->top->next->comp && stacks->stack_a->top->comp < stacks->stack_a->bottom->comp)
		{
		//	printf("swap check\n");
			swap_a(stacks);
		}
		printf("check %d %d %d\n", stacks->stack_a->top->comp, stacks->stack_a->top->next->comp, stacks->stack_a->bottom->comp);
	}
	return ;
}
