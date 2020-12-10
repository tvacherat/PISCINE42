/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 17:01:55 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/27 09:45:22 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush_02.h"

void	free_dict(t_dict *list, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		free(list[i].key);
		free(list[i].val);
		i++;
	}
	free(list);
}

char	*set_key(t_file *file, int i)
{
	char	*key;
	int		j;

	j = 0;
	while (file->buff[i] == 48 && nb_len(file->buff + i) > 1)
		i++;
	if ((key = malloc(sizeof(char) * (nb_len(file->buff + i) + 1))))
	{
		while ((file->buff[i] >= '0' && file->buff[i] <= '9') && file->buff[i])
		{
			key[j] = file->buff[i];
			i++;
			j++;
		}
		key[j] = 0;
		return (key);
	}
	return (0);
}

char	*set_val(t_file *file, int i)
{
	char	*val;
	int		j;

	j = 0;
	if ((val = malloc(sizeof(char) * (word_len(file->buff + i) + 1))))
	{
		while ((file->buff[i] > 31 && file->buff[i] < 127) && file->buff[i])
		{
			if (file->buff[i] == 32 && file->buff[i])
			{
				is_last_char(file->buff + i) == FALSE ? val[j] = 32 : 0;
				is_last_char(file->buff + i) == FALSE ? j++ : 0;
				while (file->buff[i] == 32 && file->buff[i])
					i++;
				continue ;
			}
			val[j] = file->buff[i];
			i++;
			j++;
		}
		val[j] = 0;
		return (val);
	}
	return (0);
}

t_dict	set_next_dict(t_file *file, unsigned int i)
{
	t_dict	dict;

	dict.key = set_key(file, i);
	while (file->buff[i] >= '0' && file->buff[i] <= '9' && file->buff[i])
		i++;
	while (file->buff[i] == 32 && file->buff[i])
		i++;
	i += 1;
	while (file->buff[i] == 32 && file->buff[i])
		i++;
	dict.val = set_val(file, i);
	return (dict);
}

t_dict	*set_dict(t_file *file)
{
	t_dict			*list;
	unsigned long	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!(list = malloc(sizeof(t_dict) * (get_dict_size(file)))))
		return (FALSE);
	while (file->buff[i])
	{
		while (file->buff[i] == 10 && file->buff[i])
			i++;
		if (file->buff[i])
		{
			list[j] = set_next_dict(file, i);
			j++;
		}
		while (file->buff[i] != 10 && file->buff[i])
			i++;
	}
	return (list);
}
