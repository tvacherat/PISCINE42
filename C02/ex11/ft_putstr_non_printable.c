/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 09:03:37 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/09 19:33:02 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	hprint(unsigned int n)
{
	unsigned int	i;
	static char		*hex = "0123456789abcdef";

	if (n < 0)
		return ;
	i = 1;
	while (i <= n / 16)
		i *= 16;
	write(1, "\\", 1);
	n < 16 ? write(1, "0", 1) : 0;
	while (i >= 1)
	{
		write(1, &hex[n / i], 1);
		n -= i * (n / i);
		i /= 16;
	}
}

void	ft_putstr_non_printable(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		str[i] < 32 || str[i] > 126 ? hprint((unsigned char)str[i])
			: write(1, &str[i], 1);
		i++;
	}
}
