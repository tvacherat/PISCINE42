/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 14:34:41 by tvachera          #+#    #+#             */
/*   Updated: 2021/02/08 13:05:55 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)()
		, void (*free_fct)(void *))
{
	t_list	*element;
	t_list	*temp;

	while (*begin_list && (*cmp)((*begin_list)->data, data_ref) == 0)
	{
		temp = *begin_list;
		*begin_list = (*begin_list)->next;
		(*free_fct)(temp->data);
		free(temp);
	}
	element = *begin_list;
	while (element && element->next)
	{
		if ((*cmp)(element->next->data, data_ref) == 0)
		{
			temp = element->next;
			element->next = element->next->next;
			(*free_fct)(temp->data);
			free(temp);
		}
		else
			element = element->next;
	}
}
