/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 13:46:16 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/11 12:18:15 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	unsigned int	i;
	short			is_negative;
	int				nb;

	i = 0;
	is_negative = 1;
	nb = 0;
	while (((str[i] > 8 && str[i] < 14) || str[i] == 32) && str[i])
		i++;
	while ((str[i] == 43 || str[i] == 45) && str[i])
	{
		str[i] == 45 ? is_negative *= -1 : 0;
		i++;
	}
	while ((str[i] > 47 && str[i] < 58) && str[i])
	{
		nb *= 10;
		nb += str[i] - 48;
		i++;
	}
	return (nb * is_negative);
}
