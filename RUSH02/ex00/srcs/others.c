/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 08:07:52 by ebarguil          #+#    #+#             */
/*   Updated: 2020/09/27 19:00:44 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush_02.h"

t_file	init_file(int argc, char **argv)
{
	t_file	file;

	file.name = argc == 3 ? argv[1] : DICT;
	file.size = get_file_size(file.name);
	file.must_free = FALSE;
	return (file);
}

t_num	*init_num(t_num *tab, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		tab[i].hund = -1;
		tab[i].tens = -1;
		tab[i].unit = -1;
		i++;
	}
	return (tab);
}

char	*get_nbr_stdin(void)
{
	char		buff[BUFF_SIZE];
	ssize_t		bytes;
	char		*number;
	static int	i = 0;
	static int	j = 0;

	bytes = read(0, buff, BUFF_SIZE - 1);
	buff[bytes - 1] = 0;
	if (check_nbr(buff) == FALSE)
		return (0);
	if (ft_strlen(buff) > 1)
	{
		while (buff[i] == 48 && buff[i + 1])
			i++;
	}
	if (!(number = malloc(sizeof(char) * (ft_strlen(buff + i) + 1))))
		return (0);
	while (buff[i])
	{
		number[j] = buff[i];
		i++;
		j++;
	}
	number[i] = 0;
	return (number);
}

char	*get_nbr(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) > 1)
	{
		while (str[i] == 48 && str[i + 1])
			i++;
	}
	return (str + i);
}

short	is_last_char(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 && str[i])
		i++;
	return (str[i] == 10 ? TRUE : FALSE);
}
