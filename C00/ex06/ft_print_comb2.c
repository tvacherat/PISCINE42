/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 18:41:48 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/08 09:14:48 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	display(unsigned short i, unsigned short j)
{
	char	c;

	i < 10 ? write(1, "0", 1) : 0;
	if (i >= 10)
	{
		c = i / 10 + 48;
		write(1, &c, 1);
	}
	c = i % 10 + 48;
	write(1, &c, 1);
	write(1, " ", 1);
	j < 10 ? write(1, "0", 1) : 0;
	if (j >= 10)
	{
		c = j / 10 + 48;
		write(1, &c, 1);
	}
	c = j % 10 + 48;
	write(1, &c, 1);
	i < 98 ? write(1, ", ", 2) : 0;
}

void	ft_print_comb2(void)
{
	unsigned short	nb1;
	unsigned short	nb2;

	nb1 = 0;
	while (nb1 < 99)
	{
		nb2 = nb1;
		while (nb2 < 99)
		{
			nb2++;
			display(nb1, nb2);
		}
		nb1++;
	}
}
