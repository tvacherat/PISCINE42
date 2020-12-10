/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 15:56:06 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/29 16:29:00 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*element;

	element = ft_create_elem(data);
	*begin_list ? element->next = *begin_list : 0;
	*begin_list = element;
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list			*begin;
	int				i;

	i = 0;
	begin = 0;
	if (!strs || size < 1)
		return (0);
	while (i < size)
	{
		ft_list_push_front(&begin, strs[i]);
		i++;
	}
	return (begin);
}
