/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 15:11:16 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/27 23:14:46 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush_02.h"

short	find_easy(t_dict *dict, int size, char *nbr, int nb_size)
{
	char			*val;
	int				i;
	static short	ok = TRUE;

	i = 1;
	while (i < nb_size)
	{
		if (nbr[i] != '0')
			ok = FALSE;
		i++;
	}
	if (is_key(nbr, dict, size) == TRUE)
	{
		val = get_val(dict, size, nbr);
		if (ok == TRUE && ft_strlen(nbr) > 2
			&& ft_strcmp(nbr, "10") != 0)
		{
			display_unit(dict, size, nbr[0] - 48);
			write(1, " ", 1);
		}
		write(1, val, ft_strlen(val));
		write(1, "\n", 1);
		return (TRUE);
	}
	return (FALSE);
}

short	rush(t_dict *dict, int size, char *nbr)
{
	static short	unit = -1;
	static short	tens = -1;
	static short	hund = -1;
	int				size_nbr;
	t_num			*tab;

	size_nbr = ft_strlen(nbr);
	unit = (size_nbr - 1) % 3;
	size_nbr > 1 ? tens = (size_nbr - 2) % 3 : 0;
	size_nbr > 2 ? hund = (size_nbr - 3) % 3 : 0;
	if (find_easy(dict, size, nbr, size_nbr) == TRUE)
		return (TRUE);
	else if (check_biggest_value(dict, size, size_nbr) == FALSE)
		return (FALSE);
	else if (!(tab = splash(nbr, unit, tens, hund)))
		return (FALSE);
	display(dict, size, tab, nbr);
	write(1, "\n", 1);
	free(tab);
	return (TRUE);
}

short	process(t_file *file, char *nbr)
{
	t_dict	*d_list;
	int		dict_size;

	if (!(d_list = set_dict(file)))
	{
		file->must_free == TRUE ? free(file->buff) : 0;
		return (FALSE);
	}
	dict_size = get_dict_size(file);
	file->must_free == TRUE ? free(file->buff) : 0;
	if (check_keys(d_list, dict_size) == FALSE
		|| check_dict(d_list, dict_size) == FALSE)
	{
		free_dict(d_list, dict_size);
		return (FALSE);
	}
	else if (rush(d_list, dict_size, nbr) == FALSE)
	{
		free_dict(d_list, dict_size);
		return (FALSE);
	}
	free_dict(d_list, dict_size);
	return (TRUE);
}

t_num	*splash(char *nbr, short unit, short tens, short hund)
{
	t_num	*tab;
	int		size;
	int		i;
	int		j;

	i = 0;
	j = 0;
	size = (ft_strlen(nbr) / 3) + (ft_strlen(nbr) % 3) + 1;
	if (!(tab = malloc(sizeof(t_num) * size)))
		return (0);
	tab = init_num(tab, size);
	while (nbr[i])
	{
		i % 3 == hund && nbr[i] ? tab[j].hund = nbr[i] - 48 : 0;
		i % 3 == tens && nbr[i] ? tab[j].tens = nbr[i] - 48 : 0;
		if (i % 3 == unit && nbr[i])
		{
			tab[j].unit = nbr[i] - 48;
			j++;
		}
		i++;
	}
	return (tab);
}
