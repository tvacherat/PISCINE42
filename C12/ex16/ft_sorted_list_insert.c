/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 15:26:26 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/29 16:28:12 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	l_push_front(t_list **begin_list, void *data)
{
	t_list	*element;

	element = ft_create_elem(data);
	*begin_list ? element->next = *begin_list : 0;
	*begin_list = element;
}

void	l_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*current;
	t_list	*ptr;
	void	*data;

	ptr = *begin_list;
	while (ptr)
	{
		current = *begin_list;
		while (current->next)
		{
			if ((*cmp)(current->data, current->next->data) > 0)
			{
				data = current->data;
				current->data = current->next->data;
				current->next->data = data;
			}
			current = current->next;
		}
		ptr = ptr->next;
	}
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	l_push_front(begin_list, data);
	l_sort(begin_list, cmp);
}
