/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:36:07 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/14 15:42:03 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	concat(char *chain, char **strs, char *sep, int size)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	index = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			chain[index] = strs[i][j];
			j++;
			index++;
		}
		j = 0;
		while (i < size - 1 && sep[j])
		{
			chain[index] = sep[j];
			j++;
			index++;
		}
		i++;
	}
	chain[index] = 0;
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*chain;
	int		chain_size;
	int		i;

	chain_size = 0;
	i = 0;
	while (i < size)
	{
		chain_size += ft_strlen(strs[i]);
		i < size - 1 ? chain_size += ft_strlen(sep) : 0;
		i++;
	}
	if (!(chain = malloc(sizeof(char) * chain_size + 1)))
		return (0);
	concat(chain, strs, sep, size);
	return (chain);
}
