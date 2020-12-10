/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:32:08 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/22 12:58:45 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_display_file.h"

short	display_file(char *filename)
{
	char	buff[BUFF_SIZE];
	ssize_t	bytes;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (FALSE);
	while ((bytes = read(fd, buff, BUFF_SIZE)))
	{
		if (bytes < 0)
		{
			close(fd);
			return (FALSE);
		}
		write(1, buff, bytes);
	}
	close(fd);
	return (TRUE);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		write(1, "File name missing.\n", 19);
	else if (argc > 2)
		write(1, "Too many arguments.\n", 20);
	else if (display_file(argv[1]) == FALSE)
		write(1, "Cannot read file.\n", 18);
	return (0);
}
