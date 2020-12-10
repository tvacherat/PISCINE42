/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 09:05:58 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/21 16:18:32 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tail.h"

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int				ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1 - (unsigned char)s2[i]);
}

short			is_number(char *str)
{
	unsigned int	i;

	i = 0;
	if (!(*str) || !str)
		return (FALSE);
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

short			check_args(int argc, char **argv)
{
	if (argv[1][0] != '-' && argv[1][1] != 'c')
	{
		display_text(basename(argv[0]), 2);
		display_text(": missing -c option\n", 2);
	}
	else if (argc == 2 && ft_strcmp(argv[1], "-c") == 0)
	{
		display_text(basename(argv[0]), 2);
		display_text(": option requires an argument -- c\n", 2);
	}
	else if ((argc == 2 && is_number(argv[1] + 2) == FALSE) || (argc >= 3
			&& is_number(argv[1] + 2) == FALSE && is_number(argv[2]) == FALSE))
	{
		display_text(basename(argv[0]), 2);
		display_text(" : illegal offset -- ", 2);
		display_text(ft_strlen(argv[1]) == 2 ? argv[2] : argv[1] + 2, 2);
		write(2, "\n", 1);
	}
	else
		return (TRUE);
	return (FALSE);
}

unsigned long	get_size(char *str)
{
	unsigned long	size;
	unsigned int	i;

	size = 0;
	i = 0;
	while (str[i])
	{
		size += str[i] - 48;
		if (str[i + 1])
			size *= 10;
		i++;
	}
	return (size);
}
