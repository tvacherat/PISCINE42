/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 14:07:28 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/11 16:01:57 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define FALSE 0
#define TRUE 1

short	check_base(char *base, unsigned int *base_x)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (!base || base[i] < 32 || base[i] == 43 || base[i] == 45
		|| base[i] > 126)
		return (FALSE);
	while (base[i + 1])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j] || base[j] < 32 || base[j] == 43
				|| base[j] == 45 || base[j] > 126)
				return (FALSE);
			j++;
		}
		i++;
	}
	*base_x = i + 1;
	return (*base_x < 2 ? FALSE : TRUE);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	base_x;

	i = 0;
	if (check_base(base, &base_x) == 0)
		return ;
	nbr < 0 ? write(1, "-", 1) : 0;
	nbr < 0 ? nbr *= -1 : 0;
	j = 1;
	while (j <= nbr / base_x)
		j *= base_x;
	while (j >= 1)
	{
		write(1, &base[nbr / j], 1);
		nbr -= j * (nbr / j);
		j /= base_x;
	}
}
