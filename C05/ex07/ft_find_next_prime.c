/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 10:33:38 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/13 08:58:25 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	prime;

	prime = 3;
	if (nb == 2 || nb == 3)
		return (1);
	if (nb > 1 && nb % 2 != 0)
	{
		while (prime < nb / prime && nb % prime)
			prime += 2;
		return (nb % prime == 0 ? 0 : 1);
	}
	return (0);
}

int	ft_find_next_prime(int nb)
{
	if (ft_is_prime(nb) == 1)
		return (nb);
	while (ft_is_prime(nb) == 0)
		nb++;
	return (nb);
}
