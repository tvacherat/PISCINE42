/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 15:08:47 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/29 15:26:37 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
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
