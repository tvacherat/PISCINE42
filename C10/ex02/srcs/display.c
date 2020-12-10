/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 09:05:52 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/24 10:14:04 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tail.h"

void	display_error(t_file file, char *prog_name)
{
	display_text(prog_name, 2);
	display_text(": ", 2);
	display_text(basename(file.filename), 2);
	write(2, ": ", 2);
	display_text(strerror(file.err), 2);
	write(2, "\n", 1);
}

void	display_text(char *str, unsigned int output)
{
	write(output, str, ft_strlen(str));
}

void	display_header(char *filename)
{
	display_text("==> ", 1);
	display_text(filename, 1);
	display_text(" <==\n", 1);
}

void	disp_tail(t_file file, unsigned long tail_size)
{
	unsigned char	buffer[BUFF_SIZE];
	ssize_t			bytes;
	unsigned long	to_read;

	to_read = file.size - tail_size;
	file.fd = open(file.filename, O_RDONLY);
	if (file.fd < 0)
		return ;
	while ((bytes = read(file.fd, buffer, to_read > BUFF_SIZE
		? BUFF_SIZE : to_read)))
		to_read -= bytes;
	if (bytes < 0)
		return ((void)close(file.fd));
	while ((bytes = read(file.fd, buffer, BUFF_SIZE)))
	{
		if (bytes < 0)
			return ((void)close(file.fd));
		write(1, buffer, bytes);
	}
	close(file.fd);
}

void	disp_file(t_file file)
{
	unsigned char	buffer[BUFF_SIZE];
	ssize_t			bytes;

	if (file.size == 0)
		return ;
	file.fd = open(file.filename, O_RDONLY);
	if (file.fd < 0)
		return ;
	while ((bytes = read(file.fd, buffer, BUFF_SIZE)))
	{
		if (bytes == -1)
			return ((void)close(file.fd));
		write(1, buffer, bytes);
	}
	close(file.fd);
}
