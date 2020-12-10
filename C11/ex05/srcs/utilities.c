/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 12:06:33 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/17 14:22:41 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/do_op.h"

int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int		ft_atoi(char *str)
{
	int	i;
	int	is_positive;
	int	result;

	i = 0;
	is_positive = 1;
	result = 0;
	while (str[i] && ((str[i] > 8 && str[i] < 14) || str[i] == 32))
		i++;
	while (str[i] == 43 || str[i] == 45)
	{
		str[i] == 45 ? is_positive *= -1 : 0;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	return (result * is_positive);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		return ((void)write(1, "-2147483648", 11));
	nb < 0 ? write(1, "-", 1) : 0;
	nb < 0 ? nb *= -1 : 0;
	nb >= 10 ? ft_putnbr(nb / 10) : 0;
	nb = nb % 10 + 48;
	write(1, &nb, 1);
}

short	check_params(int argc, char **argv)
{
	if (argc != 4)
		return (FALSE);
	if (ft_strcmp(argv[2], "+") && ft_strcmp(argv[2], "-")
		&& ft_strcmp(argv[2], "%") && ft_strcmp(argv[2], "/")
			&& ft_strcmp(argv[2], "*"))
	{
		write(1, "0\n", 2);
		return (FALSE);
	}
	if (ft_atoi(argv[3]) == 0 && (argv[2][0] == 37 || argv[2][0] == 47))
	{
		argv[2][0] == 37 ? write(1, "Stop : modulo by zero\n", 22)
			: write(1, "Stop : division by zero\n", 24);
		return (FALSE);
	}
	return (TRUE);
}
