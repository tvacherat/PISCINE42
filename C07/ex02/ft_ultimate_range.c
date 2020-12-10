/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 14:15:18 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/14 17:58:32 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	j;

	i = min;
	j = 0;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	if (!(range[0] = malloc(sizeof(int) * (max - min))))
		return (-1);
	while (j < max - min)
	{
		range[0][j] = i;
		i++;
		j++;
	}
	return (max - min);
}
