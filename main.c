/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <hmakida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 22:56:03 by hmakida           #+#    #+#             */
/*   Updated: 2023/09/07 12:38:50 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	list->comp = 0;
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

int	set_comp(t_stack *stack, int value)
{
	int		sum;
	t_list	*tmp;

	sum = 0;
	tmp = stack->top;
	while (tmp->data != value)
	{
		printf("set_comp check %d : %d\n", tmp->data, value);
		if (tmp->data > value)
			tmp->comp ++;
		else
			sum ++;
		tmp = tmp->next;
	}
	return (sum);
}

void	put_data_a(char **argv, t_stacks stacks)
{
	t_list	*list;
	int		i;
	int		new_comp;

	if (check_argv_one(argv) < 0)
		return ;
	list = malloc(sizeof(t_list));
	stacks.stack_a->top = list;
	list->data = ft_atoi(argv[1]);
	list->prev = NULL;
	list->comp = set_comp(stacks.stack_a, ft_atoi(argv[1]));
	list->next = NULL;
	i = 2;
	while (argv[i])
	{
		add_list_back(&list, ft_atoi(argv[i]));
		new_comp = set_comp(stacks.stack_a, ft_atoi(argv[i]));
		while (list->next != NULL)
			list = list->next;
		list->comp = new_comp;
		while (list->prev != NULL)
			list = list->prev;
		i ++;
	}
	stacks.stack_a->count = i - 1;
	while (list->next != NULL)
	{
		list = list->next;
	}
	stacks.stack_a->bottom = list;
	return ;
}

t_stack	*make_stack_b(void)
{
	t_stack	*new;

	new = malloc(sizeof (t_stack*));
	new->top = NULL;
	new->bottom = NULL;
	new->count = 0;
	return (new);
}

int	main(int argc, char *argv[])
{
	t_stacks	stacks;
	t_stack		stack_a;
	t_stack		stack_b;

	if (argc == 1)
		return (0);
	stacks.stack_a = &stack_a;
	stacks.stack_a->top = NULL;
	stacks.stack_a->bottom = NULL;
	stacks.stack_a->count = 0;
	stacks.stack_b = &stack_b;
	put_data_a(argv, stacks);
//	push_b(stacks);
//	printf("stackb %d\n", stack_b->top->comp);
	printf("check %d %d %d\n", stack_a.top->comp, stack_a.top->next->comp, stack_a.bottom->comp);
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
