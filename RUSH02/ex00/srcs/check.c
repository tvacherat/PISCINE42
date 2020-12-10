/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 09:03:28 by ebarguil          #+#    #+#             */
/*   Updated: 2020/09/27 23:16:25 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush_02.h"

short	check_buff(t_file *file)
{
	static unsigned long	i = 0;

	while (file->buff[i] == 10 && file->buff[i])
		i++;
	if ((file->buff[i] < '0' || file->buff[i] > '9') && file->buff[i])
		return (FALSE);
	while ((file->buff[i] > 47 && file->buff[i] < 58) && file->buff[i])
		i++;
	while (file->buff[i] == 32 && file->buff[i])
		i++;
	if (file->buff[i] != ':' && file->buff[i])
		return (FALSE);
	else if (file->buff[i])
		i++;
	while (file->buff[i] == 32 && file->buff[i])
		i++;
	if ((file->buff[i] < 33 || file->buff[i] > 126) && file->buff[i])
		return (FALSE);
	while (file->buff[i] > 31 && file->buff[i] < 127 && file->buff[i])
		i++;
	if (file->buff[i] != 10 && file->buff[i])
		return (FALSE);
	return (file->buff[i] ? check_buff(file) : TRUE);
}

short	check_file(t_file *file)
{
	unsigned long	index;

	index = 0;
	file->fd = open(file->name, O_RDONLY);
	if (file->fd < 0)
		return (FALSE);
	if (!(file->buff = malloc(sizeof(char) * file->size)))
		return (FALSE);
	file->must_free = TRUE;
	while ((file->bytes = read(file->fd, file->buff + index, BUFF_SIZE)))
	{
		if (file->bytes < 0)
		{
			close(file->fd);
			return (FALSE);
		}
		index += file->bytes;
	}
	close(file->fd);
	file->buff[index - 1] = 0;
	return (check_buff(file));
}

short	check_nbr(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (FALSE);
		i++;
	}
	return (i > 0 ? TRUE : FALSE);
}

short	check_dict(t_dict *list, int size)
{
	int i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		if (!(list[i].key) || !(list[i].val))
			return (FALSE);
		while (j < size)
		{
			if (ft_strcmp(list[i].key, list[j].key) == 0)
				return (FALSE);
			j++;
		}
		i++;
	}
	if (!(list[i].key) || !(list[i].val))
		return (FALSE);
	return (TRUE);
}

short	check_keys(t_dict *list, int size)
{
	static char	tab[41][37] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"
	, "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "30"
	, "40", "50", "60", "70", "80", "90", "100", "1000", "1000000"
	, "1000000000", "1000000000000", "1000000000000000", "1000000000000000000"
	, "1000000000000000000000", "1000000000000000000000000"
	, "1000000000000000000000000000", "1000000000000000000000000000000"
	, "1000000000000000000000000000000000"
	, "1000000000000000000000000000000000000"};
	int			i;

	i = 0;
	if (size < 41)
		return (FALSE);
	while (i < 41)
	{
		if (is_key(tab[i], list, size) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
