/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 15:15:38 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/29 15:26:40 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;

	i = 1;
	while (begin_list && i < nbr)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (begin_list);
}

int		ft_list_size(t_list *begin_list)
{
	int	count;

	count = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		count++;
	}
	return (count);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list			*current;
	t_list			*temp;
	t_list			*data;
	unsigned int	i;
	unsigned int	j;

	i = 1;
	j = ft_list_size(begin_list);
	while (i <= j)
	{
		current = ft_list_at(begin_list, j);
		temp = ft_list_at(begin_list, i);
		data = current->data;
		current->data = temp->data;
		temp->data = data;
		i++;
		j--;
	}
}
