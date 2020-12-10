/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 18:16:19 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/29 15:26:20 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*actual;
	t_list	*next;
	t_list	*previous;

	previous = 0;
	actual = *begin_list;
	while (actual)
	{
		next = actual->next;
		actual->next = previous;
		previous = actual;
		actual = next;
	}
	*begin_list = previous;
}
