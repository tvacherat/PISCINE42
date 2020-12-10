/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 09:28:44 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/08 13:13:16 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

short	is_last(unsigned short *tab, unsigned short size)
{
	unsigned short	i;

	i = 0;
	if (tab[0] == 10 - size)
	{
		while (i < size - 1)
		{
			if (tab[i + 1] - tab[i] != 1)
				return (1);
			i++;
		}
		return (0);
	}
	return (1);
}

short	is_sort(unsigned short *tab, unsigned short size)
{
	unsigned short	i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] >= tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	display(unsigned short *tab, unsigned short size)
{
	unsigned short	i;
	char			c;

	i = 0;
	while (i < size)
	{
		c = tab[i] + 48;
		write(1, &c, 1);
		i++;
	}
	if (is_last(tab, size))
		write(1, ", ", 2);
}

void	ft_print_combn(int n)
{
	unsigned short	tab[9];
	unsigned short	i;

	if (n > 9 || n < 1)
		return ;
	i = 0;
	while (i < 9)
	{
		tab[i] = i;
		i++;
	}
	while (is_last(tab, n))
	{
		is_sort(tab, n) == 1 ? display(tab, n) : 0;
		i = n - 1;
		tab[i] += 1;
		while (i > 0)
		{
			tab[i] > 9 ? tab[i - 1] += 1 : 0;
			tab[i] > 9 ? tab[i] = tab[i - 1] - 1 : 0;
			i--;
		}
	}
	display(tab, n);
}
