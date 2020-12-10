/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 10:43:20 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/16 14:40:49 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cat.h"

int		ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	print_stdin(void)
{
	char	buff[BUFF_SIZE];
	ssize_t	bytes;

	while ((bytes = read(0, buff, BUFF_SIZE)))
		write(1, buff, bytes);
}

void	display_error(char *filename, char *progname)
{
	write(2, progname, ft_strlen(progname));
	write(2, ": ", 2);
	write(2, filename, ft_strlen(filename));
	write(2, ": ", 2);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
}

void	ft_cat(char *filename, char *progname)
{
	char	buff[BUFF_SIZE];
	int		fd;
	ssize_t	bytes;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		display_error(filename, progname);
	else
	{
		while ((bytes = read(fd, buff, BUFF_SIZE)))
		{
			if (bytes == -1)
			{
				display_error(filename, progname);
				close(fd);
				return ;
			}
			write(1, buff, bytes);
		}
	}
	close(fd);
}

int		main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
		print_stdin();
	else if (argc > 1)
	{
		while (i < argc)
		{
			ft_cat(argv[i], basename(argv[0]));
			i++;
		}
	}
	return (0);
}
