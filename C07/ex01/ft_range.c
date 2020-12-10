/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 14:07:26 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/14 15:41:32 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;
	int	j;

	i = min;
	j = 0;
	if (min >= max || !(tab = malloc(sizeof(int) * (max - min))))
		return (0);
	while (j < max - min)
	{
		tab[j] = i;
		i++;
		j++;
	}
	return (tab);
}
