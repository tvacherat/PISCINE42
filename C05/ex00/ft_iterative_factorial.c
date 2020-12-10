/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 13:22:09 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/13 11:59:57 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	unsigned int i;
	unsigned int fact;

	i = 1;
	fact = 1;
	if (nb < 0)
		return (0);
	while (i <= (unsigned int)nb)
	{
		fact *= i;
		i++;
	}
	return (fact);
}
