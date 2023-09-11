#include	"libft/libft.h"
#include	"printf/ft_printf.h"
#include	"push_swap.h"

void	sort_two_data(t_stack *stack)
{
	if (stack->top->comp > stack->bottom->comp)
	{
		t_list	*tmp_top;

		tmp_top = stack->top;
		stack->top = stack->bottom;
		stack->bottom = tmp_top;
		stack->top->prev = NULL;
		stack->top->next = stack->bottom;
		stack->bottom->prev = stack->top;
		stack->bottom->next = NULL;
	//	ft_printf("sa\n");
	}
	return ;
}

void	sort_three_data_b(t_stack *stack)
{
//	printf("check0\n");
	if (stack->count == 2 && stack->top->comp > stack->bottom->comp)
	{
		sort_two_data(stack);
		ft_printf("sb\n");
		return ;
	}
	while (!(stack->top->comp < stack->top->next->comp && stack->top->next->comp < stack->bottom->comp))
	{
		//printf("check %d %d %d\n", stack->top->comp, stack->top->next->comp, stack->bottom->comp);
		if (stack->top->next->comp > stack->top->comp && stack->top->next->comp > stack->bottom->comp)
		{
		//	printf("ここかも\n");
			rev_rotate(stack);
			ft_printf("rrb\n");
		}
        else if (stack->top->next->comp < stack->top->comp && stack->top->comp > stack->bottom->comp)
		{
			rotate(stack);
			ft_printf("rb\n");
		}
		else if (stack->top->comp > stack->top->next->comp && stack->top->comp < stack->bottom->comp)
		{
		//	printf("swap check\n");
			swap(stack);
			ft_printf("sb\n");
		}
		//printf("check %d %d %d\n", stack->top->comp, stack->top->next->comp, stack->bottom->comp);
	}
	return ;
}


void	sort_three_data(t_stack *stack)
{
//	printf("check0\n");
	if (stack->count == 2 && stack->top->comp > stack->bottom->comp)
	{
		sort_two_data(stack);
		ft_printf("sa\n");
		return ;
	}
	while (!(stack->top->comp < stack->top->next->comp && stack->top->next->comp < stack->bottom->comp))
	{
		//printf("check %d %d %d\n", stack->top->comp, stack->top->next->comp, stack->bottom->comp);
		if (stack->top->next->comp > stack->top->comp && stack->top->next->comp > stack->bottom->comp)
		{
		//	printf("ここかも\n");
			rev_rotate(stack);
			ft_printf("rra\n");
		}
        else if (stack->top->next->comp < stack->top->comp && stack->top->comp > stack->bottom->comp)
		{
			rotate(stack);
			ft_printf("ra\n");
		}
		else if (stack->top->comp > stack->top->next->comp && stack->top->comp < stack->bottom->comp)
		{
		//	printf("swap check\n");
			swap(stack);
			ft_printf("sa\n");
		}
		//printf("check %d %d %d\n", stack->top->comp, stack->top->next->comp, stack->bottom->comp);
	}
	return ;
}
