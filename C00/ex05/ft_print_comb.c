/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 16:09:53 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/07 18:48:08 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	display(unsigned short *tab)
{
	short	i;
	char	c;

	i = 0;
	if (tab[2] > tab[1] && tab[1] > tab[0])
	{
		while (i < 3)
		{
			c = tab[i] + 48;
			write(1, &c, 1);
			i++;
		}
		tab[0] < 7 ? write(1, ", ", 2) : 0;
	}
}

void	ft_print_comb(void)
{
	unsigned short	tab[3];
	short			i;

	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	while (tab[0] < 8)
	{
		i = 2;
		tab[2] += 1;
		while (i > 0)
		{
			tab[i] == 10 ? tab[i - 1] += 1 : 0;
			tab[i] == 10 ? tab[i] = 0 : 0;
			i--;
		}
		display(tab);
	}
}
