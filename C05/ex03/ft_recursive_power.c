/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 14:02:48 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/11 14:08:18 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0 || power == 0)
		return (power < 0 ? 0 : 1);
	return (power == 1 ? nb : nb * ft_recursive_power(nb, power - 1));
}
