/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvachera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 12:04:55 by tvachera          #+#    #+#             */
/*   Updated: 2020/09/17 12:20:49 by tvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/do_op.h"

int	main(int argc, char **argv)
{
	int				i;
	static t_opp	opptab[5] = {{'+', &addition}, {'-', &substraction}
		, {'%', &modulo}, {'/', &division}, {'*', &multiplication}};

	i = 0;
	if (check_params(argc, argv) == FALSE)
		return (0);
	while (opptab[i].op != argv[2][0])
		i++;
	ft_putnbr(opptab[i].f(ft_atoi(argv[1]), ft_atoi(argv[3])));
	write(1, "\n", 1);
	return (0);
}
