/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 15:02:42 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/27 18:04:02 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush_02.h"

short	check_biggest_value(t_dict *list, int d_size, int nb_size)
{
	char			*str;
	int				biggest;
	int				i;

	biggest = 40;
	while (nb_size % 3 != 1)
		nb_size--;
	while (biggest <= nb_size)
	{
		i = 0;
		if (!(str = malloc(sizeof(char) * biggest + 1)))
			return (FALSE);
		str[0] = '1';
		while (++i < biggest)
			str[i] = '0';
		str[i] = 0;
		if (is_key(str, list, d_size) == FALSE)
		{
			free(str);
			return (FALSE);
		}
		free(str);
		biggest += 3;
	}
	return (TRUE);
}

char	*get_val(t_dict *list, int size, char *key)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (ft_strcmp(list[i].key, key) == 0)
			return (list[i].val);
		i++;
	}
	return (0);
}

int		get_dict_size(t_file *file)
{
	unsigned long	i;
	int				count;

	i = 0;
	count = 0;
	while (file->buff[i])
	{
		while (file->buff[i] && file->buff[i] == 10)
			i++;
		file->buff[i] ? count++ : 0;
		while (file->buff[i] && file->buff[i] != 10)
			i++;
	}
	return (count);
}

short	is_key(char *str, t_dict *list, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (ft_strcmp(str, list[i].key) == 0)
			return (TRUE);
		i++;
	}
	return (FALSE);
}
