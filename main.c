/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <hmakida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 22:56:03 by hmakida           #+#    #+#             */
/*   Updated: 2023/09/13 16:25:47 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "libft/libft.h"
#include    "printf/ft_printf.h"
#include    "push_swap.h"

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

int	set_comp(t_stack *stack, int value)
{
	int		sum;
	t_list	*tmp;

	sum = 0;
	tmp = stack->top;
	while (tmp->data != value)
	{
		if (tmp->data > value)
			tmp->comp ++;
		else
			sum ++;
		tmp = tmp->next;
	}
	return (sum);
}

int	put_comp_list(int i, char **argv, t_stacks stacks, t_list *list)
{
	int	new_comp;

	while (argv[i])
	{
		add_list_back(&list, ft_atoi(argv[i]));
		new_comp = set_comp(stacks.a, ft_atoi(argv[i]));
		while (list->next != NULL)
			list = list->next;
		list->comp = new_comp;
		while (list->prev != NULL)
			list = list->prev;
		i ++;
	}
	return (i);
}

void	put_data_a(char **argv, t_stacks stacks)
{
	t_list	*list;
	int		i;

	if (check_argv_one(argv) < 0)
		return ;
	list = create_list(ft_atoi(argv[1]));
	stacks.a->top = list;
	list->comp = set_comp(stacks.a, ft_atoi(argv[1]));
	i = put_comp_list(2, argv, stacks, list);
	stacks.a->count = i - 1;
	while (list->next != NULL)
		list = list->next;
	stacks.a->bottom = list;
	return ;
}

int	main(int argc, char *argv[])
{
	t_stacks	stacks;
	t_stack		stack_a;
	t_stack		stack_b;

	if (argc == 1)
		return (0);
	stacks.a = &stack_a;
	stacks.a->top = NULL;
	stacks.a->bottom = NULL;
	stacks.a->count = 0;
	stacks.b = &stack_b;
	stacks.b->count = 0;
	put_data_a(argv, stacks);
	if (stack_a.count <= 3)
		sort_three_data(&stacks);
	else if (stack_a.count <= 6)
		sort_under_seven(&stacks);
	else
		sort_over_seven(&stacks);
	return (0);
}
