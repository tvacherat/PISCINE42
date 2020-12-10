/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_file.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 16:22:35 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/22 15:52:36 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_hexdump.h"

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
		if (bytes == -1)
		{
			close(fd);
			return (0);
		}
		count += bytes;
	}
	close(fd);
	return (count);
}

void			free_file_list(unsigned int size, t_file *list)
{
	unsigned int i;

	i = 0;
	while (i < size)
	{
		close(list[i].fd);
		free(list[i].filename);
		i++;
	}
	free(list);
}

char			*ft_strcpy(char *s1)
{
	char			*str;
	unsigned int	i;

	if (!(str = malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

t_file			*get_file_list(unsigned int size, char **argv
				, unsigned short opt)
{
	unsigned int	i;
	unsigned int	j;
	t_file			*list;

	i = opt + 1;
	j = 0;
	if (!(list = malloc(sizeof(t_file) * size)))
		return (NULL);
	while (j < size)
	{
		list[j].filename = ft_strcpy(argv[i]);
		list[j].fd = open(argv[i], O_RDONLY);
		list[j].err = list[j].fd < 0 ? errno : 0;
		list[j].size = get_file_size(argv[i]);
		i++;
		j++;
	}
	return (list);
}
