/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 16:22:38 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/22 15:55:20 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_hexdump.h"

char			*putnbr_base(unsigned long nbr, char *base)
{
	char			*result;
	unsigned long	count;
	unsigned long	i;
	unsigned long	j;

	count = 1;
	i = 1;
	j = 0;
	while (i * ft_strlen(base) <= nbr)
	{
		i *= ft_strlen(base);
		count++;
	}
	if (!(result = malloc(sizeof(char) * count + 10)))
		return ("0");
	while (i >= 1)
	{
		result[j] = base[nbr / i];
		nbr -= i * (nbr / i);
		i /= ft_strlen(base);
		j++;
	}
	result[j] = 0;
	return (result);
}

unsigned int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
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

int				ft_strncmp(char *s1, char *s2, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (s1[i] == s2[i] && i < size)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void			ft_strncpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}
