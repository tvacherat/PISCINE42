/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 15:34:02 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/29 15:26:46 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

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

void	l_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*element;

	element = *begin_list1;
	if (!element && !begin_list2)
		return ;
	else if (!element)
		*begin_list1 = begin_list2;
	else
	{
		while (element->next)
			element = element->next;
		element->next = begin_list2;
	}
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2
		, int (*cmp)())
{
	l_merge(begin_list1, begin_list2);
	l_sort(begin_list1, cmp);
}
