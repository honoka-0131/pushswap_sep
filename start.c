/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <hmakida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:47:43 by hmakida           #+#    #+#             */
/*   Updated: 2023/09/13 16:19:49 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "libft/libft.h"
#include    "printf/ft_printf.h"
#include    "push_swap.h"

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
