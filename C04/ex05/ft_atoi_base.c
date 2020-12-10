/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 17:20:52 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/11 15:43:18 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FALSE 0
#define TRUE 1

short	g_is_positive = 1;

short	is_in_base(char c, char *base)
{
	unsigned int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

short	check_base(char *base, unsigned int *base_x)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (!base || base[i] < 33 || base[i] == 43 || base[i] == 45
		|| base[i] > 126)
		return (FALSE);
	while (base[i + 1])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j] || base[j] < 33 || base[j] == 43
				|| base[j] == 45 || base[j] > 126)
				return (FALSE);
			j++;
		}
		i++;
	}
	*base_x = i + 1;
	return (*base_x < 2 ? FALSE : TRUE);
}

char	*check_nbr(char *nbr, char *base)
{
	unsigned int	i;

	i = 0;
	g_is_positive = 1;
	if (!nbr)
		return (FALSE);
	while (((nbr[i] > 8 && nbr[i] < 14) || nbr[i] == 32) && nbr[i])
		i++;
	while (nbr[i] == 43 || nbr[i] == 45)
	{
		nbr[i] == 45 ? g_is_positive *= -1 : 0;
		i++;
	}
	return (is_in_base(nbr[i], base) == 0 ? FALSE : nbr + i);
}

int		ft_atoi_base(char *str, char *base)
{
	unsigned int	base_x;
	unsigned int	pow;
	unsigned int	i;
	int				nbr_size;
	int				result;

	pow = 1;
	result = 0;
	nbr_size = -1;
	str = check_nbr(str, base);
	if (check_base(base, &base_x) == FALSE || !str)
		return (FALSE);
	while (str[nbr_size + 1] && is_in_base(str[nbr_size + 1], base) == TRUE)
		nbr_size++;
	while (nbr_size >= 0)
	{
		i = 0;
		while (str[nbr_size] != base[i])
			i++;
		result += i * pow;
		pow *= base_x;
		nbr_size -= 1;
	}
	return (result * g_is_positive);
}
