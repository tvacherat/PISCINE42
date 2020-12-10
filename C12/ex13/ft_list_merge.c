/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 14:43:33 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/29 15:26:35 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
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
