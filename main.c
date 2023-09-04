#include    "libft/libft.h"
#include    "printf/ft_printf.h"
#include    "push_swap.h"

int	check_argv_two(char **argv)
{
	size_t	i;
	size_t	j;

	i = 1;
	j = i + 1;
	while (argv[i])
	{
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			{
				ft_printf("Error\n");
				return (-1);
			}
			j ++;
		}
		i ++;
		j = i + 1;
	}
	return (1);
}

int	check_argv_one(char **argv)
{
	size_t	i;
	size_t	j;

	i = 1;
	j = 0;
	while (argv[i][j])
	{
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0 && argv[i][j] != '-')
			{
				ft_printf("Error\n");
				return (-1);
			}
			j ++;
		}
		j = 0;
		i ++;
		if (argv[i] == NULL)
			break ;
	}
	return (check_argv_two(argv));
}

t_list	*create_list(int data)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->data = data;
	list->prev = NULL;
	list->next = NULL;
	return (list);
}

void	add_list_back(t_list **list, int data)
{
	t_list	*new;
	t_list	*tmp;

	tmp = *list;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	new = create_list(data);
	tmp->next = new;
	new->prev = tmp;
}

size_t	listsize(t_list *list)
{
	size_t	i;

	if (list == NULL)
		return (0);
	i = 1;
	while (list->next != NULL)
	{
		i ++;
		list = list->next;
	}
	return (i);
}

t_stack	*put_stack_a(t_list **list)
{
	t_stack	*ret;
	int		i;

	ret = malloc(sizeof(t_stack));
	ret->top = *list;
	i = 1;
	while ((*list)->next != NULL)
	{
		*list = (*list)->next;
		i ++;
	}
	ret->bottom = *list;
	ret->count = i;
	return (ret);
}

t_stack	*make_stack_a(char **argv)
{
	t_list	*list;
	size_t	i;
	size_t	list_size;

	if (check_argv_one(argv) < 0)
		return (NULL);
	list = create_list(ft_atoi(argv[1]));
	i = 2;
	while (argv[i])
	{
		add_list_back(&list, ft_atoi(argv[i]));
		i ++;
	}
	i = 0;
	list_size = listsize(list);
	while (i < list_size)
	{
		i ++;
	}
	list = compression(&list);
	return (put_stack_a(&list));
}

t_stack	*make_stack_b(void)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack*));
	new->top = NULL;
	new->bottom = NULL;
	new->count = 0;
	return (new);
}

int	main(int argc, char *argv[])
{
	t_stacks	*stacks;
	t_stack		*stack_a;
	t_stack		*stack_b;

	stack_b = NULL;
	if (argc == 1)
		return (0);
	stack_a = make_stack_a(argv);
	stack_b = make_stack_b();
	if (stack_a == NULL)
		return (0);
	stacks = malloc(sizeof(t_stacks));
	stacks->stack_a = stack_a;
	stacks->stack_b = stack_b;
	swap_a(stacks);
//	printf("stackb %d\n", stack_b->top->comp);
	printf("check %d %d %d\n", stack_a->top->comp, stack_a->bottom->prev->comp, stack_a->bottom->comp);
//	if (listsize(stack_a) <= 3)
//	{
//		sort_three_data(&stack_a);
//		return (0);
//	}
//	else if (listsize(stack_a) <= 6)
//	{
//		sort_under_seven(&stack_a, &stack_b);
//		return (0);
//	}
//	else
//		sort_over_seven(&stack_a, &stack_b);
}