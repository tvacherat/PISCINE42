/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 17:05:00 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/29 15:26:15 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void*))
{
	t_list	*element;

	while (begin_list)
	{
		element = begin_list;
		begin_list = begin_list->next;
		(free_fct)(element->data);
		free(element);
	}
}
