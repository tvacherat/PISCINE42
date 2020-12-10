/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 11:05:02 by ebarguil          #+#    #+#             */
/*   Updated: 2020/09/27 19:21:25 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush_02.h"

void	display_rank(t_dict *dict, int d_size, int index, char *nbr)
{
	char	*str;
	int		nb_z;
	char	*val;
	int		i;

	nb_z = (ft_strlen(nbr) - 1) - (3 * index);
	while (nb_z % 3 != 0)
		nb_z--;
	i = 1;
	if (!(str = malloc(sizeof(char) * (nb_z + 20))))
		return ;
	str[0] = '1';
	while (i <= nb_z)
	{
		str[i] = '0';
		i++;
	}
	str[i] = 0;
	val = get_val(dict, d_size, str);
	write(1, " ", 1);
	write(1, val, ft_strlen(val));
	free(str);
}

void	display_unit(t_dict *dict, int d_size, short nb)
{
	char	unit[2];
	char	*val;

	unit[0] = nb + '0';
	unit[1] = 0;
	val = get_val(dict, d_size, unit);
	write(1, val, ft_strlen(val));
}

void	display_spec(t_dict *dict, int d_size, short tens, short unit)
{
	char	s_tens[3];
	char	*val;

	s_tens[0] = tens + '0';
	s_tens[1] = unit + '0';
	s_tens[2] = 0;
	val = get_val(dict, d_size, s_tens);
	write(1, val, ft_strlen(val));
}

void	display_tens(t_dict *dict, int d_size, short tens)
{
	char	s_tens[3];
	char	*val;

	s_tens[0] = tens + '0';
	s_tens[1] = '0';
	s_tens[2] = 0;
	val = get_val(dict, d_size, s_tens);
	write(1, val, ft_strlen(val));
}

void	display(t_dict *dict, int d_size, t_num *num, char *nbr)
{
	static int	i = 0;
	char		*val;

	if (i > 0 && (num[i].unit > 0 || num[i].tens > 0 || num[i].hund > 0))
		write(1, " ", 1);
	if (num[i].hund > 0)
	{
		display_unit(dict, d_size, num[i].hund);
		write(1, " ", 1);
		val = get_val(dict, d_size, "100");
		write(1, val, ft_strlen(val));
		num[i].tens > 0 || num[i].unit > 0 ? write(1, " ", 1) : 0;
	}
	if (num[i].tens > 0)
	{
		num[i].tens == 1 ? display_spec(dict, d_size, num[i].tens
			, num[i].unit) : display_tens(dict, d_size, num[i].tens);
		num[i].unit > 0 && num[i].tens != 1 ? write(1, " ", 1) : 0;
	}
	if (num[i].unit > 0 && num[i].tens != 1)
		display_unit(dict, d_size, num[i].unit);
	if ((num[i].hund > 0 || num[i].tens > 0 || num[i].unit > 0)
		&& num[i + 1].unit != -1)
		display_rank(dict, d_size, i, nbr);
	return (num[i++].unit != -1 ? display(dict, d_size, num, nbr) : 0);
}
