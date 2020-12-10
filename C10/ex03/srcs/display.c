/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 16:22:26 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/22 15:44:59 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_hexdump.h"

void	display_error(t_file file, char *prog_name)
{
	display_text(basename(prog_name), 2);
	display_text(": ", 2);
	display_text(file.filename, 2);
	write(2, ": ", 2);
	display_text(strerror(file.err), 2);
	write(2, "\n", 1);
}

void	display_r_error(char *filename, char *prog_name)
{
	display_text(basename(prog_name), 2);
	display_text(": ", 2);
	display_text(filename, 2);
	write(2, ": ", 2);
	display_text(strerror(errno), 2);
	write(2, "\n", 1);
}

void	display_count(unsigned long count, unsigned short opt)
{
	char			*hex;

	hex = putnbr_base(count, "0123456789abcdef");
	write(1, "000000000", 7 + opt - ft_strlen(hex));
	display_text(hex, 1);
	write(1, "\n", 1);
	free(hex);
}

void	display_text(char *str, unsigned int output)
{
	write(output, str, ft_strlen(str));
}

int		check_args(t_file *list, unsigned int size, char *prog_name)
{
	unsigned int i;
	unsigned int ok;

	i = 0;
	ok = FALSE;
	while (i < size && ok != TRUE)
	{
		list[i].fd > 0 ? ok = TRUE : 0;
		i++;
	}
	if (ok == FALSE)
	{
		i = 0;
		while (i < size)
		{
			display_error(list[i], prog_name);
			i++;
		}
		display_text(basename(prog_name), 2);
		display_text(": ", 2);
		display_text(list[i - 1].filename, 2);
		display_text(": Bad file descriptor\n", 2);
	}
	return (ok);
}
