/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmakida <hmakida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 22:55:02 by hmakida           #+#    #+#             */
/*   Updated: 2023/09/13 15:40:14 by hmakida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "libft/libft.h"
#include    "printf/ft_printf.h"
#include    "push_swap.h"

t_list	*listfront(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp->prev != NULL)
	{
		tmp = tmp->prev;
	}
	return (tmp);
}

void	put_comp(t_list **list, int	*sort, size_t size)
{
	size_t	i;

	i = 0;
	*list = listfront(*list);
	while (i < size)
	{
		while (i < size)
		{
			if (sort[i] == (*list)->data)
			{
				(*list)->comp = i;
				i ++;
				break ;
			}
			*list = (*list)->next;
		}
		*list = listfront(*list);
	}
}

int	*make_sort(int *array, size_t size)
{
	int		tmp;
	size_t	i;
	size_t	j;

	tmp = array[0];
	i = 0;
	j = 1;
	while (i < size)
	{
		while (j < size)
		{
			if (array[j] < array[i])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			j ++;
		}
		i ++;
		j = i + 1;
	}
	return (array);
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

t_list	*compression(t_list **list)
{
	int		*array;
	int		*sort;
	size_t	i;
	size_t	list_size;

	i = 0;
	list_size = listsize(*list);
	array = malloc(sizeof(int) * list_size);
	i = 0;
	while (i < list_size)
	{
		array[i] = (*list)->data;
		i ++;
		if ((*list)->next != NULL)
			(*list) = (*list)->next;
	}
	*list = listfront(*list);
	sort = make_sort(array, listsize(*list));
	put_comp(list, sort, listsize(*list));
	return (*list);
}
