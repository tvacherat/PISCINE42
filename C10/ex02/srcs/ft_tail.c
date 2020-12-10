/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 12:35:20 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/23 16:00:26 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tail.h"

void	display_input_tail(long tail)
{
	char	*buff1;
	char	*buff2;
	ssize_t	bytes;
	long	i;
	ssize_t	old_bytes;

	if (!(buff1 = malloc(sizeof(char) * tail))
		|| !(buff2 = malloc(sizeof(char) * tail)))
		return ;
	while ((bytes = read(0, buff1, tail)))
	{
		i = -1;
		while (++i < tail)
			buff2[i] = buff1[i];
		old_bytes = bytes;
	}
	write(1, buff2 + (tail - (tail - old_bytes)), tail - old_bytes);
	write(1, buff1, old_bytes);
	free(buff1);
	free(buff2);
}

void	print_stdin(long tail)
{
	char	buff[BUFF_SIZE];
	ssize_t	bytes;
	ssize_t	old_bytes;
	long	size_input;

	size_input = 0;
	if (tail > BUFF_SIZE)
		display_input_tail(tail);
	else
	{
		while ((bytes = read(0, buff, BUFF_SIZE)))
		{
			size_input += bytes;
			old_bytes = bytes;
		}
		tail = tail > size_input ? size_input : tail;
		write(1, buff + old_bytes - tail, tail);
	}
}

void	start(t_file *list, unsigned short list_size, unsigned long tail
			, char *prog_name)
{
	unsigned int	i;
	static short	first = TRUE;

	i = 0;
	while (i < list_size)
	{
		if (list[i].err != 0)
			display_error(list[i], prog_name);
		else
		{
			if ((i > 0 && list[i - 1].fd > 0) || first != TRUE)
				write(1, "\n", 1);
			list_size > 1 ? display_header(list[i].filename) : 0;
			tail >= list[i].size ? disp_file(list[i])
				: disp_tail(list[i], tail);
			first = FALSE;
		}
		i++;
	}
}
