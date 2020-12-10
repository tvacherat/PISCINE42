/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 09:13:08 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/27 18:58:35 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush_02.h"

unsigned int	nb_len(char *str)
{
	unsigned int	i;

	i = 0;
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
		i++;
	return (i);
}

unsigned int	word_len(char *str)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while ((str[i] > 31 && str[i] < 127) && str[i])
	{
		if (str[i] == 32 && str[i])
		{
			is_last_char(str + i) == FALSE ? count++ : 0;
			while (str[i] == 32 && str[i])
				i++;
		}
		else
		{
			count++;
			i++;
		}
	}
	return (count);
}

unsigned int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int				ft_strcmp(char *s1, char *s2)
{
	unsigned int i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

unsigned long	get_file_size(char *filename)
{
	char			buff[BUFF_SIZE];
	int				fd;
	ssize_t			bytes;
	unsigned long	count;

	count = 0;
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (0);
	while ((bytes = read(fd, buff, BUFF_SIZE)))
	{
		if (bytes < 0)
		{
			close(fd);
			return (0);
		}
		count += bytes;
	}
	close(fd);
	return (count);
}
