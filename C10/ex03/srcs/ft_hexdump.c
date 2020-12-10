/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 16:22:29 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/22 15:47:54 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_hexdump.h"

void	get_line_count(char *line, unsigned long count, unsigned short index
		, unsigned short opt)
{
	unsigned int	j;
	char			*hex_count;

	hex_count = putnbr_base(count, "0123456789abcdef");
	j = 0;
	while (index < 7 + opt - ft_strlen(hex_count))
	{
		line[index] = '0';
		index++;
	}
	while (hex_count[j])
	{
		line[index] = hex_count[j];
		index++;
		j++;
	}
	free(hex_count);
}

void	get_line_hex(char *line, char *actu, unsigned short opt
		, unsigned short actu_size)
{
	unsigned int	i;
	char			*hex;
	unsigned short	index;

	i = 0;
	index = opt == 1 ? 10 : 8;
	while (i < actu_size)
	{
		hex = putnbr_base((unsigned char)actu[i], "0123456789abcdef");
		if (ft_strlen(hex) == 1)
		{
			line[index] = '0';
			line[index + 1] = hex[0];
		}
		else
		{
			line[index] = hex[0];
			line[index + 1] = hex[1];
		}
		free(hex);
		index += 3;
		index == 34 && opt == 1 ? index += 1 : 0;
		i++;
	}
}

void	get_line_txt(char *line, char *actu, unsigned int index
		, unsigned short actu_size)
{
	unsigned int	i;

	i = 0;
	line[index] = '|';
	index++;
	while (i < actu_size)
	{
		if (actu[i] < 32 || actu[i] > 126)
			line[index] = '.';
		else
			line[index] = actu[i];
		index++;
		i++;
	}
	line[index] = '|';
	line[index + 1] = 10;
	line[index + 2] = 0;
}

void	disp_line(unsigned long count, char *actu, unsigned short opt
		, unsigned short actu_size)
{
	unsigned int			i;
	static unsigned short	print = TRUE;
	static char				prev[17] = {0};
	char					line[100];

	if (ft_strncmp(actu, prev, 16) != 0)
	{
		i = 0;
		while (i++ < 99)
			line[i] = 32;
		get_line_count(line, count, 0, opt);
		get_line_hex(line, actu, opt, actu_size);
		opt == 0 ? line[55] = 10 : 0;
		opt == 0 ? line[56] = 0 : 0;
		opt == 1 ? get_line_txt(line, actu, 60, actu_size) : 0;
		write(1, line, ft_strlen(line));
		ft_strncpy(prev, actu, 16);
		print = TRUE;
		return ;
	}
	print == TRUE ? write(1, "*\n", 2) : 0;
	print = FALSE;
}

void	fill_actu(t_file file, char *actu, unsigned int *i_file
		, unsigned short *i_actu)
{
	while (*i_actu < 16 && *i_file < file.bytes)
	{
		actu[*i_actu] = file.stream[*i_file];
		*i_actu += 1;
		*i_file += 1;
	}
	actu[*i_actu] = 0;
}
