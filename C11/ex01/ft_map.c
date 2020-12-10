/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 10:31:44 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/17 14:27:18 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*new;
	int	i;

	i = 0;
	if (!tab || length < 0)
		return (0);
	new = malloc(sizeof(int) * length);
	while (i < length)
	{
		new[i] = (*f)(tab[i]);
		i++;
	}
	return (new);
}
