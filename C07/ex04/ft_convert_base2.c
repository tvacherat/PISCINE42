/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 12:47:19 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/14 14:01:15 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_atoi_base(char *str, char *base, int base_x);
int		check_base(char *base, int *base_x);

char	*get_number_base(int nbr, char *base, short start_index, int base_x)
{
	char	*result;
	int		count;
	int		i;

	count = 1;
	i = 1;
	while (i <= nbr / base_x)
	{
		i *= base_x;
		count++;
	}
	if (!(result = malloc(sizeof(char) * count + start_index)))
		return (0);
	while (i >= 1)
	{
		result[start_index] = base[nbr / i];
		nbr -= i * (nbr / i);
		i /= base_x;
		start_index++;
	}
	result[start_index] = 0;
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nbr_deci;
	char	*convert;
	int		base_from_x;
	int		base_to_x;

	if (!nbr || !(check_base(base_from, &base_from_x)))
		return (0);
	else if (!(check_base(base_to, &base_to_x)))
		return (0);
	nbr_deci = ft_atoi_base(nbr, base_from, base_from_x);
	if (nbr_deci < 0)
	{
		nbr_deci *= -1;
		convert = get_number_base(nbr_deci, base_to, 1, base_to_x);
		convert[0] = '-';
	}
	else
		convert = get_number_base(nbr_deci, base_to, 0, base_to_x);
	return (convert);
}
