/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 15:37:57 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/29 15:26:11 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*element;

	if (begin_list && *begin_list)
	{
		element = *begin_list;
		while (element->next)
			element = element->next;
		element->next = ft_create_elem(data);
	}
	else
		*begin_list = ft_create_elem(data);
}
