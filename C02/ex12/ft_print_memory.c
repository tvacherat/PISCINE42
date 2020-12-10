/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 09:42:03 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/10 12:02:48 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	get_count(char *line, unsigned long addr, unsigned short *index)
{
	unsigned int	count;
	unsigned long	i;
	static char		*base = "0123456789abcdef";

	count = 0;
	i = 1;
	while (i <= addr / 16)
	{
		i *= 16;
		count++;
	}
	while (count < 15)
	{
		line[*index] = 48;
		*index += 1;
		count++;
	}
	while (i >= 1)
	{
		line[*index] = base[addr / i];
		addr -= i * (addr / i);
		i /= 16;
		*index += 1;
	}
	index++;
}

void	get_char_hex(char *line, unsigned char *str, unsigned short *index
			, unsigned int size)
{
	unsigned int	i;
	unsigned short	j;
	unsigned short	c;
	static char		*base = "0123456789abcdef";

	i = 0;
	while (i < size && i < 16)
	{
		j = 1;
		c = str[i];
		c < 16 ? line[*index] = '0' : 0;
		c < 16 ? *index += 1 : 0;
		while (j <= c / 16)
			j *= 16;
		while (j >= 1)
		{
			line[*index] = base[c / j];
			c -= j * (c / j);
			j /= 16;
			*index += 1;
		}
		i++;
		i % 2 == 0 ? line[*index] = 32 : 0;
		i % 2 == 0 ? *index += 1 : 0;
	}
}

short	get_printables(char *line, char *str, unsigned short *index
			, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size && i < 16)
	{
		line[*index] = str[i] < 32 || str[i] > 126 ? 46 : str[i];
		*index += 1;
		i++;
	}
	return (i);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char			line[80];
	unsigned short	index;
	unsigned short	bytes;

	while (size > 0)
	{
		index = 0;
		get_count(line, (unsigned long)addr, &index);
		line[index++] = ':';
		line[index++] = 32;
		get_char_hex(line, (unsigned char *)addr, &index, size);
		while (index < 58)
			line[index++] = 32;
		bytes = get_printables(line, (char *)addr, &index, size);
		line[index++] = 10;
		write(1, line, index);
		addr += bytes;
		size -= bytes;
	}
	return (addr);
}
